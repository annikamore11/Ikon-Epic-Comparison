//
// Created by Annika More on 2/19/23.
//

#ifndef M2OEP_AHMORE_COMPARISON_H
#define M2OEP_AHMORE_COMPARISON_H
#include <iostream>
#include <sstream>
#include "SkiPass.h"
using namespace std;

class Comparison{
private:
    vector<Resort> allResorts;
    stringstream ss;
public:
    /*
     * This constructor takes in the dataset I am using to be able to send to other classes.
     * It will set allResorts to this vector.
     */
    Comparison(vector<Resort> allResorts);

    /*
     * PrintOptions outputs the comparison options that the user can choose from
     */
    void printOptions();

    /*
     * compareByHeight is used in option2 to sort the vector by height
     * compareByYear is used in option3 to sort the vector by year
     * compareBySnow is used in option4 to sort the vector by average snow
     */
    static bool compareByHeight(const Resort &a, const Resort &b);
    static bool compareByYear(const Resort &a, const Resort &b);
    static bool compareBySnow(const Resort &a, const Resort &b);

    // getAllResorts will return the allResorts field
    vector<Resort> getAllResorts();

    /*
     * Option1 will return a string that has a general comparison of the Ikon and Epic pass
     * Option2 will return a vector containing the tallest shortest resorts on the Ikon and Epic pass
     * Option 3 will return a vector containing the oldest mountains out of all the resorts
     * Option 4 will return a vector containing the resorts with the highest average snowfall out of all resorts
     */
    string option1();
    vector<Resort> option2();
    vector<Resort> option3();
    vector<Resort> option4();
};

#endif //M2OEP_AHMORE_COMPARISON_H
