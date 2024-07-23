#include <iostream>
#include <cstdlib> 
#include <ctime>    
using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0))); 

    int secretnum = rand() % 100 + 1; 
    int guesses;
    int attempts = 0;
    bool correct = false;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have chosen a number between 1 and 100. Try to guess it." << endl;

    while (!correct) {
        cout << "Enter your guess: ";
        cin >> guesses;
        attempts++;

        if (guesses == secretnum) {
            cout << "Congratulations! You guessed the number in " << attempts << " attempts." << endl;
            correct = true;
        } else if (guesses < secretnum) {
            cout << "Too low. Try again." << endl;
        } else {
            cout << "Too high. Try again." << endl;
        }
    }

    return 0;
}
