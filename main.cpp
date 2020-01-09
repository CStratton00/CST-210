//
// Created by Collin Stratton on 1/9/2019
// This is my own work
//

#include <iostream>
#include <cmath>

using namespace std;
int main() {
//    int lbs = 0;
//    cout << "Please enter your weight in pounds: " << endl;
//    cin >> lbs;
//
//    double kilo = lbs * .454;
//
//    cout << "Your weight in kilos is: " << kilo;

    double s = 0.0;
    cout << "Please enter the side of a hexagon: " << endl;
    cin >> s;

    double area = ((3 * sqrt(3)) / 2) * pow(s, 2);

    cout << "Area of the hexagon is: " << area;

    return 0;
}
