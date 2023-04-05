//
// Created by Annika More on 2/19/23.
//
#include "Comparison.h"
#include <iostream>
#include <algorithm>
using namespace std;

Comparison:: Comparison(vector<Resort> allResorts){
    this->allResorts = allResorts;
}

void Comparison:: printOptions(){
    cout << "Options (type d when done)" << endl;
    cout << "1: A general comparison between the Ikon and Epic pass" << endl;
    cout << "2: The shortest and tallest ski resorts on the Ikon and Epic pass" << endl;
    cout << "3: Resorts that have been open the longest" << endl;
    cout << "4: Resorts with the most snowfall" << endl;
    cout << "5: Visualizations of The Data" << endl;
}



bool Comparison:: compareByHeight(const Resort &a, const Resort &b) {
    return a.getSize().getHeight() < b.getSize().getHeight();
}
bool Comparison:: compareByYear(const Resort &a, const Resort &b) {
    return a.getYearsOpen() > b.getYearsOpen();
}
bool Comparison:: compareBySnow(const Resort &a, const Resort &b) {
    return a.getAveSnow() > b.getAveSnow();
}



vector<Resort> Comparison:: getAllResorts(){
    return allResorts;
}




string Comparison:: option1(){
    // create Ikon pass and find average snow, vertical drop, and acres for all the mountains on the pass
    // Also find how many limited and unlimited resorts are on the pass.
    SkiPass ikon(allResorts, "Ikon");
    double aveISnow = ikon.getAveSnow();
    double aveIVert = ikon.getAveVert();
    double aveIAcres = ikon.getAveAcres();
    ikon.setLimited();
    ikon.setUnlim();
    int limitedIRes = ikon.getLimited();
    int unlimIRes = ikon.getUnlim();

    // create Epic pass and find average snow, vertical drop, and acres for all the mountains on the pass
    // Also find how many limited and unlimited resorts are on the pass.
    SkiPass epic(allResorts, "Epic");
    double aveESnow = epic.getAveSnow();
    double aveEVert = epic.getAveVert();
    double aveEAcres = epic.getAveAcres();
    epic.setLimited();
    epic.setUnlim();
    int limitedERes = epic.getLimited();
    int unlimERes = epic.getUnlim();

    // Use a stringstream to return results in a way that can be easily outputted to file
    ss << "Pass," << "Average Resort Snowfall," << "Average Vertical Drop," << "Average Skiable Terrain,"
    << "# Limited Resorts, " << "# Unlimited Resorts" << endl << ikon.getName() << "," << aveISnow << " in,"
    << aveIVert << " ft," << aveIAcres << " acres," << limitedIRes << "," << unlimIRes << endl << epic.getName() << ","
    << aveESnow << " in," << aveEVert << " ft," << aveEAcres << " acres," << limitedERes << "," << unlimERes;

    return ss.str();
}


vector<Resort> Comparison:: option2(){
    // Make Ikon and Epic passes and separate into different vectors
    SkiPass ikon(allResorts, "Ikon");
    SkiPass epic(allResorts, "Epic");
    vector<Resort> ikonResorts = ikon.getPassResorts();
    vector<Resort> epicResorts = epic.getPassResorts();
    // Make a vector that will contain all of the shortest and tallest mountains from each pass
    vector<Resort> fullVec;
    vector<Resort> ikonT;
    vector<Resort> ikonS;
    vector<Resort> epicT;
    vector<Resort> epicS;


    // Sort the resorts on each pass by height
    sort(ikonResorts.begin(), ikonResorts.end(), compareByHeight);
    sort(epicResorts.begin(), epicResorts.end(), compareByHeight);


    // the end of the sorted vector will be the tallest mountains for Ikon
    for (int i=ikonResorts.size()-1; i>ikonResorts.size()-6; i--){
        ikonT.push_back(ikonResorts[i]);
    }

    // The beginning of the sorted vector will be the shortest for Ikon
    for (int i=0; i<5; i++){
        ikonS.push_back(ikonResorts[i]);
    }

    // the end of the sorted vector will be the tallest mountains for Epic
    for (int i=epicResorts.size()-1; i>epicResorts.size()-6; i--){
        epicT.push_back(epicResorts[i]);
    }

    // The beginning of the sorted vector will be the shortest for Epic
    for (int i=0; i<5; i++){
        epicS.push_back(epicResorts[i]);
    }

    for (int i=0; i<5; i++){
        fullVec.push_back(ikonT[i]);
        fullVec.push_back(ikonS[i]);
        fullVec.push_back(epicT[i]);
        fullVec.push_back(epicS[i]);
    }
    return fullVec;
}


vector<Resort> Comparison:: option3(){
    // sort the full vector by year and keep the oldest resorts which in this case will be at the beginning of the vector
    vector<Resort> oldest;
    sort(allResorts.begin(), allResorts.end(), compareByYear);
    for(int i=0; i<8; i++){
        oldest.push_back(allResorts[i]);
    }
    return oldest;

}

// sort the full vector by average snow and keep the resorts with the most snow which in this case will be at the beginning of the vector
vector<Resort> Comparison:: option4(){
    vector<Resort> mostSnow;
    sort(allResorts.begin(), allResorts.end(), compareBySnow);
    for(int i=0; i<10; i++){
        mostSnow.push_back(allResorts[i]);
    }
    return mostSnow;

}


