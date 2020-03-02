//
// Created by Collin Stratton on 2/4/20.
//

#ifndef MASTERMIND_GUESS_H
#define MASTERMIND_GUESS_H

#include <stdio.h>

using namespace std;

class Guess {
private:
    int guess[4] = {0, 0, 0, 0};

public:
    Guess();
    void setGuess(int a, int b, int c, int d);
    void generateCode();

    bool isValid(int x);
    int operator[](int index);
};

Guess::Guess() {                                                // Guess Constructor
}

void Guess::setGuess(int a, int b, int c, int d) {              // Sets the guess of the user to a guess object
    if(isValid(a) && isValid(b) && isValid(c) && isValid(d)) {  // Checks to see if the inputs are valid
        guess[0] = a;
        guess[1] = b;
        guess[2] = c;
        guess[3] = d;
    } else {
        cout << "Invalid inputs given" << endl;                 // Outputs the invalid value given
        if(a < 0) {
            guess[0] = -1;
            cout << "First input " << a + 1 << " is less than 0, values should be between 1 and 6" << endl;
        } else if(a > 5) {
            guess[0] = -1;
            cout << "First input " << a + 1 << " is greater than 6, values should be between 1 and 6" << endl;
        }

        if(b < 0) {
            guess[1] = -1;
            cout << "Second input " << b + 1 << " is less than 0, values should be between 1 and 6" << endl;
        } else if(b > 5) {
            guess[1] = -1;
            cout << "Second input " << b + 1 << " is greater than 6, values should be between 1 and 6" << endl;
        }

        if(c < 0) {
            guess[2] = -1;
            cout << "Third input " << c + 1 << " is less than 0, values should be between 1 and 6" << endl;
        } else if(c > 5) {
            guess[2] = -1;
            cout << "Third input " << c + 1 << " is greater than 6, values should be between 1 and 6" << endl;
        }

        if(d < 0) {
            guess[3] = -1;
            cout << "Fourth input " << d + 1 << " is less than 0, values should be between 1 and 6" << endl;
        } else if(d > 5) {
            guess[3] = -1;
            cout << "Fourth input " << d + 1 << " is greater than 6, values should be between 1 and 6" << endl;
        }
    }
}

void Guess::generateCode() {                                    // Generates a secret code for the key object
    srand(time(NULL));

    guess[0] = rand() % 6;
    guess[1] = rand() % 6;
    guess[2] = rand() % 6;
    guess[3] = rand() % 6;
}

bool Guess::isValid(int x) {                                    // Checks to see if the inputted value is greater than 0 and less than 7
    return x <= 5 && x >= 0;
}

int Guess::operator[](int index) {                              // Guess operator that allows us to return the value at the index given
    return guess[index];
}


#endif //MASTERMIND_GUESS_H
