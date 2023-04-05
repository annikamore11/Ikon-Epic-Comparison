#include "Resort.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


Resort:: Resort(){
    location = "";
    resort = "";
    pass = "";
    limUnlim = "";
    sizeMount = Size();
    projDaysOpen = 0;
    yearsOpen = 0;
    aveSnow = 0;
    begRun = 0;
    exRun = 0;
}


Resort:: Resort(string location, string resort,
        string pass, string limUnlim, Size sizeMount, int projDaysOpen,
        int yearsOpen, int aveSnow, int begRun, int exRun){
    this->location = location;
    this->resort = resort;
    this->pass = pass;
    this->limUnlim = limUnlim;
    this->sizeMount = sizeMount;
    this->projDaysOpen = projDaysOpen;
    this->yearsOpen = yearsOpen;
    this->aveSnow = aveSnow;
    this->begRun = begRun;
    this->exRun = exRun;
}

//Getters
string Resort::getLoc() const {
    return location;
}
string Resort::getResort() const {
    return resort;
}
string Resort::getPass() const {
    return pass;
}

string Resort::getLimited() const {
    return limUnlim;
}

Size Resort::getSize() const {
    return sizeMount;
}

int Resort::getDaysOpen() const {
    return projDaysOpen;
}
int Resort::getYearsOpen() const {
    return yearsOpen;
}
int Resort::getAveSnow() const {
    return aveSnow;
}
int Resort::getBegRun() const {
    return begRun;
}
int Resort::getExRun() const {
    return exRun;
}




vector<Resort> Resort::getDataFromFile(string filename, vector<Resort>& skiMoun){
    ifstream fileIn;
    // Open the file
    fileIn.open(filename);

    string header;
    if(fileIn){
        getline(fileIn, header);
    }

    // Declare variables to be read in
    string junk;
    int summitInt, vertInt, acreInt;
    char comma;

    // for each line, if value is null set to default value, and then store the value in specific field
    string line;
    while (getline(fileIn, line)) {
        istringstream iss(line);

        if (!getline(iss, location, ',')) {
            location = "";
        }


        if (!getline(iss, resort, ',')) {
            resort = "";
        }

        if (!getline(iss, pass, ',')) {
            pass = "";
        }

        if (!getline(iss, limUnlim, ',')) {
            limUnlim = "";
        }
        getline(iss, junk, ',');

        if (!(iss >> summitInt)) {
            summitInt = 0;
        }
        iss.ignore();

        if (!(iss >> vertInt)) {
            vertInt = 0;
        }
        iss.ignore();

        getline(iss, junk, ',');
        getline(iss, junk, ',');
        getline(iss, junk, ',');

        if (!(iss >> acreInt)) {
            acreInt = 0;
        }
        iss.ignore();

        getline(iss, junk, ',');
        getline(iss, junk, ',');
        getline(iss, junk, ',');

        if (!(iss >> projDaysOpen)) {
            projDaysOpen = 0;
        }
        iss.ignore();
        getline(iss, junk, ',');

        if (!(iss >> yearsOpen)) {
            yearsOpen = 0;
        }
        iss.ignore();

        if (!(iss >> aveSnow)) {
            aveSnow = 0;
        }
        iss.ignore();

        if (!(iss >> begRun)) {
            begRun = 0;
        }

        iss.ignore();

        getline(iss, junk, ',');
        getline(iss, junk, ',');


        if (!(iss >> exRun)) {
            exRun = 0;
        }

        getline(iss, junk, ',');

        // for each line make a Resort object by calling the Resort constructor and passing it all the parameters
        // add to the vector of all resorts
        skiMoun.emplace_back(location, resort, pass, limUnlim, Size(summitInt,vertInt, acreInt), projDaysOpen,
                                 yearsOpen, aveSnow, begRun, exRun);
    }

    fileIn.close();
    return skiMoun;
}