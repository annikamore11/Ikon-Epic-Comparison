//
// Created by Annika More on 2/16/23.
//

#ifndef M2OEP_AHMORE_RESORT_H
#define M2OEP_AHMORE_RESORT_H
#include <iostream>
#include <vector>
#include "Size.h"
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// This class is a parent class to Size and a Resort object has a Size object
// This class is a child class to skiPass as a skiPass has 1 or more Resorts
class Resort{
private:
    //Declare all of the variables
    string location;
    string resort;
    string pass;
    string limUnlim;
    Size sizeMount;
    int projDaysOpen;
    int yearsOpen;
    int aveSnow;
    int begRun;
    int exRun;



public:
    // Default Constructor takes in no parameters and sets fields to 0, or empty string
    Resort();
    // Constructor takes in all the fields of the resort and sets the fields to their values
    Resort(string location, string resort,
         string pass, string limUnlim, Size sizeMount, int projDaysOpen,
         int yearsOpen, int aveSnow, int begRun, int exRun);

    //Getters
    string getLoc() const;
    string getResort() const;
    string getPass() const;
    string getLimited() const;
    Size getSize() const;
    int getDaysOpen() const;
    int getYearsOpen() const;
    int getAveSnow() const;
    int getBegRun() const;
    int getExRun() const;





// Overloaded operator for a resort object
    friend ostream& operator << (ostream& outs, const Resort&  skiMoun){
        outs << setw(10) << right << skiMoun.getLoc();
        outs << setw(15) << right << skiMoun.getResort();
        outs << setw(8) << right << skiMoun.getPass();
        outs << setw(20) << right << skiMoun.getLimited();
        outs << setw(15) << right << skiMoun.getSize().getHeight();
        outs << setw(15) << right << skiMoun.getSize().getVertical();
        outs << setw(15) << right << skiMoun.getSize().getAcres();
        outs << setw(20) << right << skiMoun.getDaysOpen();
        outs << setw(20) << right << skiMoun.getYearsOpen();
        outs << setw(20) << right << skiMoun.getAveSnow();
        outs << setw(20) << right << skiMoun.getBegRun();
        outs << "   " << skiMoun.getExRun();
        return outs;
    }

    //method that takes in a filename and copy of a vector
    vector<Resort> getDataFromFile(string filename, vector<Resort>& skiMoun);

};

#endif //M2OEP_AHMORE_RESORT_H
