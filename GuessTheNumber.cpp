// Assignment 01 - Guess The Number
#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main() {

    srand((unsigned int)time(NULL));
    int number = rand() % 100 + 1; // Logic for choose number from 1 to 100
    int guess = 0;

    do {
        cout << "Guess a number between 1 and 100: ";
        cin >> guess;

        if(guess > number)
            cout << "Guess Lower!" << endl;
        else if(guess < number)
            cout << "Guess Higher!" << endl;
        else
            cout << "You guessed it! The number was " << number << endl;

    } while(guess != number); // The loop runs until guessing number is equal to random Number

    return 0;
}