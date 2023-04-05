//
// Created by Annika More on 2/16/23.
//

#ifndef M2OEP_AHMORE_SIZE_H
#define M2OEP_AHMORE_SIZE_H

#include <iostream>
using namespace std;

// This class is a child class to Resort as a Resort has a Size
class Size {
private:
    // declare fields
    int heightMount;
    int vertical;
    int terrainAcres;
public:
    // Default constructor sets fields to 0
    Size();

    // Constructor takes in height, vertical drop and acres of skiable terrain from the resort class and sets the fields to those values
    Size(int heightMount, int vertical, int terrainAcres);

    // getters return fields
    int getHeight() const;
    int getVertical() const;
    int getAcres() const;
};


#endif //M2OEP_AHMORE_SIZE_H
