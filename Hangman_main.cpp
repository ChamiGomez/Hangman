//Program: Hangman
//This file contains the main function from C_Hangman.h

#include "C_Hangman.h"
#include <iostream>
#include <conio.h>

int main(void) {
	//Game Setup
	C_Hangman game;
	game.Generate_Answer();
	game.Process_Problem();
	
	cout << "\n\nThe problem is:\n";
	Display_Problem(game.answer_chars);
	char guessed_letter = 'a'; //Dummy initialisation
	do {
		cout << "Please guess a letter: ";
		//Check letter hasn't already been guessed
		bool already_guessed_letter = false;
		do {
			guessed_letter = toupper(_getch());
			already_guessed_letter = false; //For repeated loops
			for (int i = 0; i < game.correct_letters.size(); i++) {
				if (guessed_letter == game.correct_letters[i]) {
					cout << "\nYou have already guessed " << guessed_letter << " correctly!\nPlease enter a new letter: ";
					already_guessed_letter = true;
					break;
				}
			}
			if (!already_guessed_letter) {
				for (int i = 0; i < game.incorrect_letters.size(); i++) {
					if (guessed_letter == game.incorrect_letters[i]) {
						cout << "\nYou have already guessed " << guessed_letter << " incorrectly!\nPlease enter a new letter: ";
						already_guessed_letter = true;
						break;
					}
				}
			}
		} while (already_guessed_letter);
		//Game mechanics
		game.Process_Guess(guessed_letter);
		game.Display_Status();
		Display_Man(game.num_incorrect_guesses);
		//End of game handling
		if (game.correct_letters.size() == game.letters.size()) break;
		(game.num_incorrect_guesses < 8) ? cout << "\n\n" : cout << "\n\nGame Over! Better luck next time!\n";
	} while (game.num_incorrect_guesses < 8);

	//Output end of game information
	if (game.num_incorrect_guesses < 8) cout << "\nCongratulations!\n\n";
	else {
		cout << "The correct answer was:\n";
		for (int i = 0; i < game.answer_chars.size(); i++) {
			for (int j = 0; j < game.answer_chars[i].size(); j++)
				cout << game.answer_chars[i][j];
			cout << " ";
		}
		cout << "\n\n";
	}

	return 0;
}