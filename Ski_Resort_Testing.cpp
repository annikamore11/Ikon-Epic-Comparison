//
// Created by Annika More on 2/23/23.
//
#include "Comparison.h"
#include "SkiPass.h"
#include "Resort.h"
#include "Size.h"
#include <iostream>
using namespace std;

bool test_Comparison();
bool test_SkiPass();
bool test_Resort();
bool test_Size();

int main() {

    if (test_Comparison()) {
        cout << "Passed all Comparison test cases" << endl;
    }

    if (test_SkiPass()) {
        cout << "Passed all Ski Pass test cases" << endl;
    }


    if (test_Resort()) {
        cout << "Passed all Resort test cases" << endl;
    }


    if (test_Size()) {
        cout << "Passed all Size test cases" << endl;
    }
    return 0;
}

bool test_Comparison(){
    bool passed = true;
    // create the vector of skiresorts like used in the program
    vector<Resort> skiResorts;
    // create a Resort object
    Resort r;
    // get the data from the file like we would in the program
    r.getDataFromFile("../skiresorts.csv", skiResorts);
    Comparison c(skiResorts);
    if (c.getAllResorts().size() != 87){
        cout << "FAILED Comparison parameter constructor and getter test case" << endl;
        passed = false;
    }

    if (c.option1() == ""){
        cout << "FAILED Comparison option 1 test" << endl;
        passed = false;
    }

    vector<Resort> sam = c.option2();
    if (sam[0].getSize().getHeight() != 13050 || sam[1].getSize().getHeight() != 1120 || sam[2].getSize().getHeight() != 13150 ||
    sam[3].getSize().getHeight() != 1030){
        cout << "FAILED Comparison option 2 test" << endl;
        passed = false;
    }

    vector<Resort> oldestRes = c.option3();
    if (oldestRes[0].getResort() != "Mt. Norquay" || oldestRes[1].getResort() != "Sunshine Village"){
        cout << "FAILED Comparison option 3 test" << endl;
        passed = false;
    }

    vector<Resort> mostSnow = c.option4();
    if (mostSnow[0].getResort() != "Alta" || mostSnow[1].getResort() != "Snowbird"){
        cout << "FAILED Comparison option 4 test" << endl;
        passed = false;
    }

    return passed;
}


bool test_SkiPass() {
    bool passed = true;

    // make a SkiPass object and dont pass it anything, variables should all be set to 0 or empty or empty string
    SkiPass pass;
    if(pass.getTotSnow() != 0 || pass.getName() != "" || pass.getNumResorts() != 0 || pass.getTotVert() != 0 || pass.getTotAcres() != 0 ||
    pass.getLimited() != 0 ||pass.getUnlim() != 0){
        cout << "FAILED Ski Pass default constructor and getter test case" << endl;
        passed = false;
    }

    // create the vector of skiresorts like used in the program
    vector<Resort> skiResorts;
    // create a Resort object
    Resort r;
    // get the data from the file like we would in the program
    r.getDataFromFile("../skiresorts.csv", skiResorts);

    // Pass the parameter constructor the vector with pass name ikon. Everything should be set to 0, empty string, but
    // getPassResorts should be the size of all the ikon resorts and numResorts should be the vector size of passResorts
    SkiPass p(skiResorts, "Ikon");
    if(p.getPassResorts().size() != 41 || p.getTotSnow() != 0 || p.getName() != "Ikon" || p.getNumResorts() != p.getPassResorts().size() ||
    pass.getTotVert() != 0 || pass.getTotAcres() != 0 || pass.getLimited() != 0 ||pass.getUnlim() != 0){
        cout << "FAILED Ski Pass parameter constructor and getter test case" << endl;
        passed = false;
    }

    // Create a sample Resort and vector to test adding and getting average snow of a pass
    // only keep the first index of skiResorts and add it to the vector
    // Pass the sample vec with the pass name of the sample resort
    Resort sampleRes = skiResorts[0];
    vector<Resort> sampleVec;
    sampleVec.push_back(sampleRes);
    SkiPass adding(sampleVec, "Ikon");


    // These test both the getters for aveSnow etc and addSnow etc.
    // test the passes getAveSnow which should return the value of that resorts average snow since there is only 1 resort in vector
    if (adding.getAveSnow() != 547){
        cout << "FAILED Ski Pass adding snow test case" << endl;
        passed = false;
    }

    // test the passes getAveAcres which should return the value of that resorts acres since there is only 1 resort in vector
    if (adding.getAveAcres() != 2614){
        cout << "FAILED Ski Pass adding acres test case" << endl;
        passed = false;
    }

    // test the passes getAveVer which should return the value of that resorts vert since there is only 1 resort in vector
    if (adding.getAveVert() != 2538){
        cout << "FAILED Ski Pass adding vertical test case" << endl;
        passed = false;
    }

    return passed;
}


bool test_Resort() {
    bool passed = true;
    Resort r;
    if (r.getLoc() != "" || r.getResort() != "" || r.getPass() != "" || r.getLimited() != "" || r.getSize().getHeight() != 0 ||
    r.getSize().getAcres() != 0 || r.getSize().getVertical() != 0 || r.getDaysOpen() != 0 || r.getYearsOpen() != 0 || r.getAveSnow() != 0 ||
    r.getBegRun() != 0 || r.getExRun() != 0){
        cout << "FAILED Resort default constructor test case" << endl;
        passed = false;
    }
    Size s(12000, 2000, 3500);
    Resort r2("Colorado", "A-Basin", "Ikon", "Limited", s, 340, 100, 350, 14, 10);
    if (r2.getLoc() != "Colorado" || r2.getResort() != "A-Basin" || r2.getPass() != "Ikon" || r2.getLimited() != "Limited" || r2.getSize().getHeight() != s.getHeight() ||
        r2.getSize().getAcres() != s.getAcres() || r2.getSize().getVertical() != s.getVertical() || r2.getDaysOpen() != 340 || r2.getYearsOpen() != 100 || r2.getAveSnow() != 350 ||
        r2.getBegRun() != 14 || r2.getExRun() != 10){
        cout << "FAILED Resort parameter constructor test case as well as getter test cases" << endl;
        passed = false;
    }

    vector<Resort> skiResorts;
    r.getDataFromFile("../skiresorts.csv", skiResorts);
    Resort specRes = skiResorts[0];


    if (specRes.getLoc() != "utah" || specRes.getResort() != "Alta" || specRes.getPass() != "Ikon" || specRes.getLimited() != "limited" || specRes.getSize().getHeight() != 11068 ||
        specRes.getSize().getAcres() != 2614 || specRes.getSize().getVertical() != 2538 || specRes.getDaysOpen() != 142 || specRes.getYearsOpen() != 84 || specRes.getAveSnow() != 547 ||
        specRes.getBegRun() != 0 || specRes.getExRun() != 0){
        cout << "FAILED reading file test case" << endl;
        passed = false;
    }
    return passed;
}



bool test_Size() {
    bool passed = true;
    Size s;
    if (s.getHeight() != 0 || s.getAcres() != 0 || s.getVertical() !=0){
        cout << "FAILED Size default constructor test case" << endl;
        passed = false;
    }

    Size s2(12000, 3500, 2000);
    if (s2.getHeight() != 12000 || s2.getVertical() != 3500 || s2.getAcres() != 2000){
        cout << "FAILED Size parameter constructor test case and getter test cases" << endl;
        passed = false;
    }

    return passed;
}
