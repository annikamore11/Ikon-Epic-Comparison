//
// Created by Annika More on 2/18/23.
//

#ifndef M2OEP_AHMORE_SKIPASS_H
#define M2OEP_AHMORE_SKIPASS_H
#include <iostream>
#include "Resort.h"
using namespace std;


// Represents a Parent class Pass that has 1 or more Resort objects
// This is "has a" relationship and represents composition
class SkiPass {
private:
    // declare fields
    vector<Resort> passResorts;
    string name;
    int numResorts;
    int snowfall;
    int vertical;
    int acres;
    int limited;
    int unlim;

public:
    // default constructor sets fields to 0, or empty strings
    SkiPass();

    // constructor takes in the vector of all resorts and the name of the pass
    // it will set the fields to default values except for the passResorts
    // passResorts will contain all of the resorts that are on the pass specified by passName
    SkiPass(vector<Resort>& skiResorts, string passName);

    // setters for certain fields
    void setNumResorts(int sizeVec);
    // below setters loop through pass resorts and find how many limited and unlimited resorts there are
    void setLimited();
    void setUnlim();

    /*
     * getAveSnow loops through pass resorts and calls addSnow to get total snowfall for all the resorts on the pass
     * It will then find the average
     */
    double getAveSnow();
    /*
     * getAveVert loops through pass resorts and calls addVert to get total snowfall for all the resorts on the pass
     * It will then find the average
     */
    double getAveVert();
    /*
     * getAveAcres loops through pass resorts and calls addAcres to get total snowfall for all the resorts on the pass
     * It will then find the average
     */
    double getAveAcres();

    // simple getters below
    string getName();
    int getNumResorts();
    vector<Resort> getPassResorts();
    int getLimited();
    int getUnlim();
    int getTotSnow();
    int getTotVert();
    int getTotAcres();

    // below functions will keep a running total
    void addSnow(Resort resort);
    void addVert(Resort resort);
    void addAcres(Resort resort);

};

#endif //M2OEP_AHMORE_SKIPASS_H
