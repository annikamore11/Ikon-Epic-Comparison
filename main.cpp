//
// Created by Annika More on 2/16/23.
//
# include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib> // for system()
#include <string>
#include "Resort.h"
#include "Comparison.h"
using namespace std;

// Declare the global functions for user validation
// testing
vector<int> getUserInput();
void call_R_script_with_dataset(const string& dataset_path);
int main() {
    // create a vector that will contain all of the ski resorts from the dataset
    vector<Resort> skiResorts;

    // create an instance of the Resort class so the data can be read from the file
    Resort resort;
    // Call the Resort method passing the filename and vector
    resort.getDataFromFile("../skiresorts.csv", skiResorts);

    // create an instance of the Comparison class and send it the vector of all resorts
    Comparison compare(skiResorts);
    // Ask user what comparisons they would like to see and print the options
    cout << "What comparison(s) would you like to see?" << endl;
    compare.printOptions();
    // Call the getUserInput method that will return a vector of the options the user wants to see
    vector<int> userChoices = getUserInput();

    // loop through the users choices and call functions
    for (int i=0; i<userChoices.size(); i++) {
        // if the option is 1 open the option 1 file and output the string stream returned by option1 function in comparison class
        if (userChoices[i] == 1) {
            ofstream outfile1;
            outfile1.open("../Option 1: General Comparison.csv");
            outfile1 << compare.option1() << endl;
            outfile1.close();
        }

        // if option is 2 open the option 2 file and call the function
        if (userChoices[i] == 2) {
            ofstream outfile2;
            outfile2.open("../Option 2: Biggest and Smallest Resorts.csv");

            string formatVec = "";
            string num;
            // call the option2 function in Comparison to get the vector of big and small resorts
            vector<Resort> bigSmallRes = compare.option2();
            // loop through the vector and add to a string the name of the resort and its height
            // if the index is divisible by 4 it should start a new line
            for (int i = 0; i < bigSmallRes.size(); i++)
            {
                if ((i+1)%4 == 0){
                    formatVec +=  bigSmallRes[i].getResort() + ": " + to_string(bigSmallRes[i].getSize().getHeight())+ " ft" + "\n";
                }
                else{
                    formatVec += bigSmallRes[i].getResort() + ": " + to_string(bigSmallRes[i].getSize().getHeight()) + " ft" + ",";
                }
            }
            outfile2 << "Ikon Tallest Resorts," << "Ikon Smallest Resorts," << "Epic Tallest Resorts," << "Epic Smallest Resorts" << endl
            << formatVec;
            outfile2.close();
        }

        // if choice is 3, open the output file for option 3
       else if (userChoices[i] == 3){
            ofstream outfile3;
            outfile3.open("../Option 3: Oldest Resorts on The Ikon and Epic Passes.csv");
            // call the option3 function and store results in a vector
            vector<Resort> oldestRes = compare.option3();

            // output certain variables from the vector
            outfile3 << "Location," << "Resort," << "Years Open," << "Pass" << endl;
            for (Resort r: oldestRes){
                outfile3 << r.getLoc() << "," << r.getResort() << "," << r.getYearsOpen() << "," << r.getPass() << endl;
            }

            outfile3.close();
       }

       // if option is 4 open file
        else if (userChoices[i] == 4){
            ofstream outfile4;
            outfile4.open("../Option 4: Most Snowfall.csv");

            // call option4 function and store in vector
            vector<Resort> mostSnow = compare.option4();
            outfile4 << "Location," << "Resort," << "Average Snow Per Season," << "Pass" << endl;
            for (Resort r: mostSnow){
                outfile4 << r.getLoc() << "," << r.getResort() << "," << r.getAveSnow() << "," << r.getPass() << endl;
            }

            outfile4.close();
        }

        else {
            string dataPath = "/Users/annikamore/Desktop/Ikon-Epic-Comparison/skiresorts.csv";
            call_R_script_with_dataset(dataPath);
        }

    }
}



// get user input for snowfall amount and validate it as an integer
vector<int> getUserInput(){

    // create a struct that will have input and num
    struct {
        int num;
        string input;
    } results;

    stringstream ss;
    vector<int> choices;

    // get the user input
    getline(cin, results.input);

    // Copy the string into the string stream
    ss << results.input;

    // while the input is not "d" prompt the user
    while(results.input != "d"){
        // if no input, reprompt, clear the string stream, and copy new input into string stream
        if (results.input.length() < 1) {
            cout << "No input. Enter choice: ";
            getline(cin, results.input);
            stringstream().swap(ss);
            ss << results.input;
        }

            // if reading the string stream into an integer is false, reprompt, clear, and copy new input
        else if (!(ss >> results.num)){
            cout << "Invalid input: Enter amount: ";
            getline(cin, results.input);
            stringstream().swap(ss);
            ss << results.input;
        }

            // if the string stream does not reach till the end of the string without being an error, reprompt
        else if (!ss.eof()){
            cout << "Invalid input: Enter amount: ";
            getline(cin, results.input);
            stringstream().swap(ss);
            ss << results.input;
        }

            // if the input is successfully validated as an integer, if it is less than 0, reprompt.
        else if(results.num <= 0 || results.num > 5){
            cout << "Invalid option: Enter choice: ";
            getline(cin, results.input);
            stringstream().swap(ss);
            ss << results.input;
        }

            // If string is validated into an integer put the value in the snowfall vector, and reprompt.
        else {
            choices.push_back(results.num);
            cout << "Next option? (or d if done) ";
            getline(cin, results.input);
            stringstream().swap(ss);
            ss << results.input;
        }


    }

    // return the vector of snowfall integers
    return choices;
}


void call_R_script_with_dataset(const string& dataset_path) {
    string command = "Rscript /Users/annikamore/Desktop/Ikon-Epic-Comparison/skiGraphs.R " + dataset_path;
    system(command.c_str());
}
