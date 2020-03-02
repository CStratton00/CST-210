//
// Created by Collin Stratton on 2/4/20.
//

#ifndef MASTERMIND_GAME_H
#define MASTERMIND_GAME_H

#include "Guess.h"

using namespace std;

class Game {
private:
    Guess userGuess;
    Guess secretCode;

    int whitePegs;
    int blackPegs;
    int numGuesses;

public:
    Game();
    void GetUserGuess();
    void GiveFeedback();

    bool IsWinner();
    bool IsLoser();

    void PlayGame();
};

Game::Game() {                                          // Initializes Game and its variables
    whitePegs = 0;
    blackPegs = 0;
    numGuesses = 10;
    secretCode.generateCode();
}

void Game::GetUserGuess() {                             // Asks the user for a guess
    int a, b, c, d;
    cout << "Input your guess: "; cin >> a >> b >> c >> d;

    userGuess.setGuess(a-1, b-1, c-1, d-1);// Sets the guess the the object userGuess
}

void Game::GiveFeedback() {                             // Returns feedback regarding the number of whitePegs and blackPegs awarded
    int codeColors[6] = {0, 0, 0, 0, 0, 0};
    int guessColors[6] = {0, 0, 0, 0, 0 ,0};
    blackPegs = 0;
    whitePegs = 0;

    for(int i=0; i<4; i++) {                            // Loops 4 times and assigns values to codeColors, guessColors,
        codeColors[secretCode[i]] ++;                   // and checks userGuess to secretCode
        guessColors[userGuess[i]] ++;
        if(userGuess[i] == secretCode[i]) {
            blackPegs++;
        }
    }

    for(int i=0; i<6; i++) {                            // Checks to see if codeColors and guessColors have any values that are the same
        if(min(codeColors[i], guessColors[i]) > 0) {
            whitePegs++;
        }
    }
    if(whitePegs - blackPegs >= 0) {whitePegs -= blackPegs;} else {whitePegs = 0;}
}

bool Game::IsWinner() {                                 // Returns true if there are 4 black pegs
    return blackPegs == 4;
}

bool Game::IsLoser() {                                  // Returns true if the number of guess is 0
    return numGuesses == 0;
}

void Game::PlayGame() {                                 // Runs the code to play the game
    cout << "Enter 4 values between 1 and 6" << endl;
    cout << "The secret code is: "; for(int i = 0; i<4; i++) {cout << secretCode[i]+1;}
    cout << endl;
    cout << "<-------------------------------->" << endl;
    while(!IsWinner()) {                                // Checks if the user has won
        if (IsLoser()) {                                // Checks if the user has lost
            cout << "Game Over" << endl;
            cout << "The answer was: "; for(int i = 0; i<4; i++) {cout << secretCode[i]+1;}
            break;
        } else {                                        // Grabs a user guess and gives feedback accordingly
            GetUserGuess();
            GiveFeedback();
            cout << "White Pegs: " << whitePegs << endl;
            cout << "Black Pegs: " << blackPegs << endl;
            numGuesses--;
            cout << "Number of Guess Left: " << numGuesses << endl;
            cout << "<-------------------------------->" << endl;
        }
    }
    if(IsWinner()) {
        cout << "You Win!!" << endl;
    }
}

#endif //MASTERMIND_GAME_H
