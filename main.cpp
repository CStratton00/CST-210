//
// Created by Collin Stratton on 1/9/2019
// This is my own work
//

#include <iostream>

using namespace std;
int main() {
    int lbs = 0;
    cout << "Please enter your weight in pounds: " << endl;
    cin >> lbs;

    double kilo = lbs * .454;

    cout << "Your weight in kilos is: " << kilo;
    return 0;
}
