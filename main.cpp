//
// Created by Collin Stratton on 1/9/2019
// This is my own work
//

#include <iostream>
#include <cmath>

using namespace std;
int main() {
//    Weight Program
    int lbs = 0;
    cout << "Please enter your weight in pounds: " << endl;
    cin >> lbs;

    double kilo = lbs * .454;

    cout << "Your weight in kilos is: " << kilo;

//    Area Program
    double s = 0.0;
    cout << "Please enter the side of a hexagon: " << endl;
    cin >> s;

    double area = ((3 * sqrt(3)) / 2) * pow(s, 2);

    cout << "Area of the hexagon is: " << area;

//  Larger Value Program
    int x = 0;
    int y = 0;

    cout << "Enter the first value: " << endl;
    cin >> x;
    cout << "Enter the second value: " << endl;
    cin >> y;

    if(x > y) {
        cout << "The first value is the larger value at: " << x;
    } else {
        cout << "The second value is the larger value at: " << y;
    }

    return 0;
}
