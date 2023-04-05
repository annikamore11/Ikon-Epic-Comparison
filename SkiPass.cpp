//
// Created by Annika More on 2/18/23.
//
#include "SkiPass.h"
using namespace std;

SkiPass::SkiPass() {
    snowfall = 0;
    name = "";
    numResorts = passResorts.size();
    vertical = 0;
    acres = 0;
    limited = 0;
    unlim = 0;
}

SkiPass::SkiPass(vector<Resort>& skiResorts, string passName) {
    passResorts.clear();
    // loop through vector to find all resorts on specified pass
    for (int i = 0; i<skiResorts.size(); i++){
        if (skiResorts[i].getPass() == passName){
            passResorts.push_back(skiResorts[i]);
        }
    }
    snowfall = 0;
    name = passName;
    numResorts = passResorts.size();
    vertical = 0;
    acres = 0;
    limited = 0;
    unlim = 0;
}

void SkiPass::setNumResorts(int sizeVec){
    numResorts = sizeVec;
}

void SkiPass::setLimited() {
    for (int i=0; i<passResorts.size(); i++){
        if (passResorts[i].getLimited() == "limited"){
            limited++;
        }
    }
}

void SkiPass::setUnlim() {
    for (int i=0; i<passResorts.size(); i++){
        if (passResorts[i].getLimited() == "unlimited"){
            unlim++;
        }
    }
}


double SkiPass::getAveSnow() {
    for (int i=0; i<passResorts.size(); i++){
        addSnow(passResorts[i]);
    }
    return (double)snowfall/numResorts;
}

double SkiPass::getAveVert() {
    for (int i=0; i<passResorts.size(); i++){
        addVert(passResorts[i]);
    }
    return (double)vertical/numResorts;
}

double SkiPass::getAveAcres() {
    for (int i=0; i<passResorts.size(); i++){
        addAcres(passResorts[i]);
    }
    return (double)acres/numResorts;
}

string SkiPass::getName() {
    return name;
}

int SkiPass::getNumResorts() {
    return numResorts;
}

vector<Resort> SkiPass:: getPassResorts(){
    return passResorts;
}

int SkiPass::getLimited() {
    return limited;
}

int SkiPass::getUnlim() {
    return unlim;
}

int SkiPass::getTotSnow() {
    return snowfall;
}

int SkiPass::getTotVert() {
    return vertical;
}

int SkiPass::getTotAcres() {
    return acres;
}


void SkiPass::addSnow(Resort resort) {
    snowfall+=resort.getAveSnow();
}

void SkiPass::addVert(Resort resort) {
    vertical+=resort.getSize().getVertical();
}

void SkiPass::addAcres(Resort resort) {
    acres+=resort.getSize().getAcres();
}






