#include<iostream>
#include<cstdlib> // for Rand() and srand()
#include<ctime> // For time()

using namespace std;

// Function to get the user's choice
string getUserChoice() {
    string userInput;
    cout << "Enter your choice (rock, paper, scissors): ";
    cin >> userInput;

    // Convert input to lowercase
    for(char &c : userInput) {
        c = tolower(c);
    }

    // Validate Input
    while(userInput != "rock" && userInput != "paper" && userInput != "scissors") {
        cout << "Invalid choice. Please try again." << endl;
        cout << "Enter your choice(rock, paper, scissors): ";
        cin >> userInput;
        for(char &c : userInput) {
            c = tolower(c);
        }
    }

    return userInput;
}

// Function to get the computer's choice
string getComputerChoice() {
    srand(time(0)); // seed the random number generator
    int randomNum = rand() % 3; // Generate a random number between 0 and 2

    switch(randomNum) {
        case 0: return "rock";
        case 1: return "paper";
        case 2: return "scissors";
        default: return ""; // This should never happen
    }
}

// Function to determine the Winner
string determineWinner(string userChoice, string computerChoice) {
    if(userChoice == computerChoice) {
        return "It;s a tie!";
    }
    else if ((userChoice == "rock" && computerChoice == "scissors") ||
             (userChoice == "paper" && computerChoice == "rock") ||
             (userChoice == "scissors" && computerChoice == "paper")) {
        
            return "You Win!";

    }
    else {
        return "You Lose!";
    }
}

// Main function to play the game
void playGame() {
    cout << "Welcome to Rock-Paper-Scissors!" << endl;

    string userChoice = getUserChoice();
    string computerChoice = getComputerChoice();

    cout << "You choose: " << userChoice << endl;
    cout << "Computer choose: " << computerChoice << endl;

    string result = determineWinner(userChoice, computerChoice);
    cout << result << endl;
}

int main() {
    playGame(); // Start the Game
    return 0;
}