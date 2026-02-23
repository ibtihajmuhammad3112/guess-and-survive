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

// ================= BORDER =================
int printLine() {
    setColor(11);
    cout << "\n======================================\n";
    setColor(7);

    setColor(10);
    cout << "\n						Select Difficulty Level:\n";
    setColor(11);
    cout << "						1. Easy (10 lives)\n";
    cout << "						2. Medium (7 lives)\n";
    cout << "						3. Hard (5 lives)\n";
    cout << "						4. Extreme (3 lives)\n";
    setColor(7);

    int maxIncorrectGuesses;
    int choice = _getch() - '0';
    cout << choice << endl;

    switch (choice) {
        case 1: maxIncorrectGuesses = 10; break;
        case 2: maxIncorrectGuesses = 7;  break;
        case 3: maxIncorrectGuesses = 5;  break;
        case 4: maxIncorrectGuesses = 3;  break;
        default: maxIncorrectGuesses = 7;
    }

    setColor(7);

    return maxIncorrectGuesses;
}

// Select random word
string selectRandomWord() {
    vector<string> wordList;

    wordList.push_back("programming");
    wordList.push_back("condition");
    wordList.push_back("repitition");
    wordList.push_back("variable");
    wordList.push_back("algorithm");
    wordList.push_back("function");
    wordList.push_back("compiler");
    wordList.push_back("comments");
    wordList.push_back("operator");
    
    srand(static_cast<unsigned int>(time(0)));
    return wordList [rand() % wordList .size()];
    int index = rand() % wordList.size();
    return wordList[index];

}

int main() {
	
	srand(time(0));
    bool playAgain = true;
    while(playAgain) {
    	
    setColor(4);
    cout << "\n						UNIVERSITY OF CENTRAL PUNJAB\n";

    // ================= LOADING ANIMATION =================
    setColor(13);
    cout << "\n					 _    _                                         \n";
    cout << "					| |  | |                                        \n";
    cout << "					| |__| | __ _ _ __   __ _ _ __ ___   __ _ _ __  \n";
    cout << "					|  __  |/ _` | '_ \\ / _` | '_ ` _ \\ / _` | '_ \\ \n";
    cout << "					| |  | | (_| | | | | (_| | | | | | | (_| | | | |\n";
    cout << "					|_|  |_|\\__,_|_| |_|\\__, |_| |_| |_|\\__,_|_| |_|\n";
    cout << "					                     __/ |                      \n";
    cout << "					                    |___/                       \n\n";
    setColor(7);
    Sleep(1000);
    cout << "\nLoading Game";
    for (int i = 0; i < 6; i++) {
        cout << ".";
        Sleep(400);
    }
    cout << "\n\n";
    Sleep(800);

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
    cout << "						Welcome to Guess and Survive!\n";
    cout << "						A Hangman word guessing game.\n";
    cout << "						Guess the hidden word before it's too late!\n\n";

    setColor(6);
    cout << "   						 * BCCS-B1\n";
    cout << "   						 * FALL 2025\n" << endl;

    // Credits
    cout << "					======================================\n";
    setColor(14);
    cout << "					|	Presented By:		     |	\n\n";

    setColor(9);
    cout << "  					|	 * Ibtihaj Muhammad	     |\n";
    cout << "   					|	 * Muhammad Zazaan Qazi	     |\n";
    cout << "   					|	 * Arslan Mehmood	     |\n";
    cout << "   					|	 * Kashif Ali	  	     |\n";
     cout << "					=======================================\n";
    
	setColor(2);
	cout<<"\n==========================================="<<endl;
	cout<<"|";setColor(6);cout<<"            Rank system";setColor(2);cout<<"                  |"<<endl;
	setColor(2);
	cout<<"|";setColor(13);cout<<" Score                    Rank";setColor(2);cout<<"           |"<<endl;
	setColor(12);
	cout<<"| 0-30                     Beginner       |"<<endl;
	cout<<"| 31-60                    Fighter        |"<<endl;
	cout<<"| 61-100                   Survivor       |"<<endl;
	cout<<"| 100+                     Hangman Master |"<<endl;
	setColor(2);
	cout<<"==========================================="<<endl;
	
    // Start Prompt
    setColor(9);
    cout << "\nPress Enter to Start the Game...";
    setColor(7);
    cin.get();

    // Game setup
    string secretWord = selectRandomWord();
    string guessedWord(secretWord.length(), '_');
    vector<char> guessedLetters;
	int maxIncorrectGuesses = printLine();
    int incorrectGuesses = 0;
    int consecutiveWrong = 0;
    bool dealOffered = false;
    bool hintGiven = false;
    int score = 0; // <- NEW: Score system

    setColor(4); // Red color
    cout << "\n						You have " << maxIncorrectGuesses << " incorrect guesses allowed." << endl;
    setColor(11);
    cout << "\n						The word has " << secretWord.length() << " letters." << endl;
    setColor(7); // Reset to default color

    // ================= GAME LOOP =================
    while (incorrectGuesses < maxIncorrectGuesses && guessedWord != secretWord) {
    	setColor(12);
    	cout<<"\n					================================================="<<endl;
        setColor(10);
        cout << "					|	Current word: " << guessedWord <<"			|" << endl;
        cout << "					|	Enter your guess (single letter):	| ";
        setColor(7); // Reset to default color

        char guess = _getch(); // Instant input
        cout << guess << endl;
        guess = tolower(guess);

        // Check if already guessed
        if (find(guessedLetters.begin(), guessedLetters.end(), guess) != guessedLetters.end()) {
            setColor(1);
            cout << "					You already guessed that letter. Try another one." << endl;
            setColor(7);
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
            cout << "					|	Good job! The letter '" << guess << "' is in the word.|" << endl;
            score += 10; // <- NEW: +10 for correct guess
            consecutiveWrong = 0;
             // ====== LIVE SCORE DISPLAY ======
    setColor(14);
    cout << "					|	Current Score: " << score <<"			|"<< endl;
    cout<<"					================================================="<<endl;
    setColor(7);
} 
        else {
            incorrectGuesses++;
            consecutiveWrong++;
            score -= 5; // <- NEW: -5 for wrong guess
            if (score < 0) score = 0; // Prevent negative score

            setColor(3);
            cout << "					|	Sorry,the letter '" << guess << "' is not in the word.|" << endl;
            cout << "					|	Incorrect guesses: ";
            setColor(4);
            cout << incorrectGuesses << "/" << maxIncorrectGuesses<<"			|" << endl;
            setColor(7);
             // ====== LIVE SCORE DISPLAY ======
    setColor(14);
    cout << "					|	Current Score: " << score <<"			|"<< endl;
    cout<<"					================================================="<<endl;
    setColor(7);

        }

        // Deal offer after 2 consecutive wrong guesses
        if (consecutiveWrong == 2 && !dealOffered && incorrectGuesses < maxIncorrectGuesses) {
            setColor(8);
            cout << "\n					*** SPECIAL DEAL ***" << endl;
            cout << "					You've made 2 consecutive wrong guesses!" << endl;
            cout << "					We can reveal a letter for you, but it will cost 2 lives." << endl;
            cout << "					Enter 1 for YES (accept deal) or 2 for NO (reject deal): ";
            setColor(7);

            int dealChoice = _getch() - '0'; // convert char to int
            cout << dealChoice << endl;

            if (dealChoice == 1) {
                // Reveal a letter
                for (size_t i = 0; i < secretWord.length(); ++i) {
                    if (guessedWord[i] == '_') {
                        char revealedLetter = secretWord[i];
                        for (size_t j = 0; j < secretWord.length(); ++j) {
                            if (secretWord[j] == revealedLetter) {
                                guessedWord[j] = revealedLetter;
                            }
                        }
                        guessedLetters.push_back(revealedLetter);
                        setColor(13);
                        cout << "					Letter revealed: '" << revealedLetter << "'" << endl;
                        incorrectGuesses += 2; // Cost: 2 lives
                        setColor(4);
                        cout << "					You now have " << incorrectGuesses << "/" << maxIncorrectGuesses << " incorrect guesses." << endl;
                        break;
                    }
                }
                consecutiveWrong = 0;
                dealOffered = true;
            } else {
                cout << "Deal rejected! Continue playing..." << endl;
                setColor(7);
                dealOffered = true;
            }
        }
    }

    // ================= GAME OVER =================
    if (guessedWord == secretWord) {
        score += 20; // <- NEW: Bonus for winning
        setColor(3);
        cout << "\n	Congratulations! You've guessed the word: " << secretWord << endl;
          // Print final ASCII for hangman
    cout << "        ___________\n";
    cout << "        |         |\n";
    cout << "        |         |\n";
    cout << "        |         \n";
    cout << "        |         O\n";
    cout << "        |        /|\\ \n";
    cout << "     ___|___     / \\	\n\n";
    } 
	else {
        setColor(4);
        cout << "\nGame over! The word was: " << secretWord << endl;
        // Print final ASCII for hangman
    cout << "        ___________\n";
    cout << "        |         |\n";
    cout << "        |         |\n";
    cout << "        |         O\n";
    cout << "        |        /|\\ \n";
    cout << "        |        / \\ \n";
    cout << "     ___|___     \n\n";
    }

    

    // ================= FINAL SCORE & RANK =================
    setColor(13);
    string rank;
    if (score <= 30) rank = "Beginner";
    else if (score <= 60) rank = "Fighter";
    else if (score <= 100) rank = "Survivor";
    else rank = "Hangman Master";

    cout << "						Final Score: " << score << endl;
    cout << "						Rank: " << rank << endl;
	setColor(9);
	cout << "\n						Play Again? (Y/N): ";
        char ch;
        cin >> ch;
        if(tolower(ch) != 'y') playAgain = false;
    setColor(7); // Reset color
    
}
    cout << "\nThanks for Playing!\n";
    return 0;
}
