#include <iostream>
#include <conio.h>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

// Function to change text color
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

string selectRandomWord() {
	
    vector<string> wordList;
    wordList.push_back("programming");
    wordList.push_back("condition");
    wordList.push_back("repitition");
    wordList.push_back("variable");
    wordList.push_back("function");
    wordList.push_back("algorithm");
    wordList.push_back("compiler");
    wordList.push_back("comments");
    wordList.push_back("operator");
    wordList.push_back("hangman");
    wordList.push_back("language");
    
    srand(static_cast<unsigned int>(time(0)));
    int index = rand() % wordList.size();
    return wordList[index];
}

int main() {
	setColor(4);
	cout<<"						UNIVERSITY OF CENTRAL PUNJAB\n";

    // Title
    setColor(11);
    cout << "\n					=========================================\n";
    cout << "        		 			     GUESS AND SURVIVE\n";
    cout << "           					        HANGMAN GAME\n";
    cout << "					=========================================\n\n";

    // Hanging Wood & Rope ASCII Art
    setColor(6); // Brownish (Yellow)
    cout << "        ___________\n";
    cout << "        |         |\n";
    cout << "        |         |\n";
    cout << "        |         |\n";
    cout << "        |         |\n";
    cout << "        |         O\n";
    cout << "        |	 /|\\\n";
    cout << "     ___|___     / \\\n\n";

    // Description
    setColor(10);
    cout << "Welcome to Guess and Survive!\n";
    cout << "A Hangman word guessing game.\n";
    cout << "Guess the hidden word before it's too late!\n\n";

	setColor(6);
	cout << "    * BCCS-B1\n";
    cout << "    * FALL 2025\n"<<endl;

    // Credits
    setColor(14);
    cout << "Presented By:\n\n";
    
    setColor(13);
    cout << "    * Ibtihaj Muhammad\n";
    cout << "    * Muhammad Zazaan Qazi\n";
    cout << "    * Arslan Mehmood\n";
    cout << "    * Kashif Ali\n\n";

    // Start Prompt
    setColor(9);
    cout << "Press Enter to Start the Game...";
    setColor(7);
    cin.get();

    string secretWord = selectRandomWord();
    string guessedWord(secretWord.length(), '_');
    vector<char> guessedLetters;
    int maxIncorrectGuesses = 7;
    int incorrectGuesses = 0;
    int consecutiveWrong = 0;
    bool dealOffered = false;
    bool hintGiven = false;

    setColor(4); // Red color
	cout << "\nYou have " << maxIncorrectGuesses << " incorrect guesses allowed." << endl;
	setColor(11);
	cout << "The word has " << secretWord.length() << " letters." << endl;
	setColor(7); // Reset to default color	

    while (incorrectGuesses < maxIncorrectGuesses && guessedWord != secretWord) {
    	setColor(10);
        cout << "\nCurrent word: " << guessedWord << endl;
        cout << "Enter your guess (single letter): ";
        setColor(7); // Reset to default color
         
        
     char guess;
	guess = _getch();              // Takes input instantly (no Enter needed)
	cout << guess << endl;         // Show the typed character on screen
	guess = tolower(guess);	

        // Check if the letter was already guessed
        if (find(guessedLetters.begin(), guessedLetters.end(), guess) != guessedLetters.end()) {
        	setColor(1); 
            cout << "You already guessed that letter. Try another one." << endl;
            setColor(7); // Reset to default color
            continue;
        }

        guessedLetters.push_back(guess);
        bool correctGuess = false;

        for (size_t i = 0; i < secretWord.length(); ++i) {
            if (secretWord[i] == guess) {
                guessedWord[i] = guess;
                correctGuess = true;
            }
        }

        if (correctGuess) {
        	setColor(6);
            cout << "Good job! The letter '" << guess << "' is in the word." << endl;
            setColor(7); // Reset to default color
            consecutiveWrong = 0; // Reset consecutive wrong counter
        } else {
            incorrectGuesses++;
            consecutiveWrong++;
            setColor(3);
            cout << "Sorry, the letter '" << guess << "' is not in the word." << endl;
            
            cout << "Incorrect guesses: ";
            setColor(4);
			cout<< incorrectGuesses << "/" << maxIncorrectGuesses << endl;
            setColor(7); // Reset to default color

            // Deal offer after 2 consecutive wrong guesses
            if (consecutiveWrong == 2 && !dealOffered && incorrectGuesses < maxIncorrectGuesses) {
            	setColor(8);
                cout << "\n*** SPECIAL DEAL ***" << endl;
                cout << "You've made 2 consecutive wrong guesses!" << endl;
                cout << "We can reveal a letter for you, but it will cost 2 lives." << endl;
                cout << "Enter 1 for YES (accept deal) or 2 for NO (reject deal): ";
                setColor(7); // Reset to default color
                int dealChoice;
				dealChoice = _getch();     // take input instantly (no Enter)
				cout << dealChoice << endl; // show the pressed key
				dealChoice -= '0';  

                if (dealChoice == 1) {
                    // Find an unrevealed letter
                    for (size_t i = 0; i < secretWord.length(); ++i) {
                        if (guessedWord[i] == '_') {
                            char revealedLetter = secretWord[i];
                            // Reveal all instances of this letter
                            for (size_t j = 0; j < secretWord.length(); ++j) {
                                if (secretWord[j] == revealedLetter) {
                                    guessedWord[j] = revealedLetter;
                                }
                            }
                            guessedLetters.push_back(revealedLetter);
                            setColor(13);
                            cout << "Letter revealed: '" << revealedLetter << "'" << endl;
                            incorrectGuesses += 2; // Cost: 2 lives
                            setColor(4);
                            cout << "You now have " << incorrectGuesses << "/" << maxIncorrectGuesses << " incorrect guesses." << endl;
                            
                            break;
                        }
                    }
                    consecutiveWrong = 0;
                    dealOffered = true;
                } else {
                    cout << "Deal rejected! Continue playing..." << endl;
                    setColor(7); // Reset to default color
                    dealOffered = true; // Mark deal as offered (can only be offered once)
                }
            }

        }
    }

    if (guessedWord == secretWord) {
    	setColor(3);
        cout << "\nCongratulations! You've guessed the word: " << secretWord << endl;
            cout << "        ___________\n";
    cout << "        |         |\n";
    cout << "        |         |\n";
    cout << "        |         |\n";
    cout << "        |         \n";
    cout << "        |         O\n";
    cout << "        |	 /|\\\n";
    cout << "     ___|___     / \\\n\n";
    } else {
    	setColor(4);
        cout << "\nGame over! The word was: " << secretWord << endl;
        
             cout << "        ___________\n";
    cout << "        |         |\n";
    cout << "        |         |\n";
    cout << "        |         O\n";
     cout << "        |        /|\\ \n";
    cout << "        |        / \\\n";
    cout << "        |         \n";
    cout << "        |	 \n";
    cout << "     ___|___     \n\n";
     setColor(7); // Reset to default color
    }

    return 0;
}
