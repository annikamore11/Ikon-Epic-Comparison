//
// Created by Annika More on 2/16/23.
//
#include "Size.h"

Size::Size() {
    heightMount = 0;
    vertical = 0;
    terrainAcres = 0;
}

Size::Size(int heightMount, int vertical, int terrainAcres) {
    this->heightMount = heightMount;
    this->vertical = vertical;
    this->terrainAcres = terrainAcres;
}

int Size::getHeight() const {
    return heightMount;
}

int Size::getVertical() const {
    return vertical;
}

int Size::getAcres() const {
    return terrainAcres;
}