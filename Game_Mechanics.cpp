//Program: Hangman
//This file contains the game mechanics functions from C_Hangman.h which are required for the game to run

#include "C_Hangman.h"
#include <iostream>

void C_Hangman::Process_Problem(void) {
	for (int i = 0; i < answer_chars.size(); i++) { //For each word
		for (int j = 0; j < answer_chars[i].size(); j++) { //For each letter
			if (i == 0 && j == 0) { //First letter
				letters.push_back(answer_chars[i][j]);
				letter_uses.push_back(1);
			}
			else {
				bool recurring_letter = false;
				for (int k = 0; k < letters.size(); k++) {
					if (answer_chars[i][j] == letters[k]) { //Letter already used
						recurring_letter = true;
						letter_uses[k]++;
						break;
					}
				}
				if (!recurring_letter) { //New letter
					letters.push_back(answer_chars[i][j]);
					letter_uses.push_back(1);
				}
			}
		}
	}
}

void C_Hangman::Process_Guess(const char guessed_letter) {
	bool correct_guess = false;
	for (int i = 0; i < letters.size(); i++) {
		if (guessed_letter == letters[i]) { //Correct letter guess
			correct_guess = true;
			correct_letters.push_back(guessed_letter);
			num_output_correct_letters += letter_uses[i];
			break;
		}
	}
	if (!correct_guess) { //Incorrect letter guess
		incorrect_letters.push_back(guessed_letter);
		num_incorrect_guesses++;
	}
}

void C_Hangman::Display_Status(void) {
	if (correct_letters.empty()) { //Only incorrect letter guessed
		cout << "\nIncorrect guessed letters: ";
		for (int i = 0; i < incorrect_letters.size(); i++) {
			cout << incorrect_letters[i];
			if (i != incorrect_letters.size() - 1) cout << ",\t";
		}
		cout << endl;
		Display_Problem(answer_chars);
	}
	else { //Some correct letters
		int correct_letter_counter = 0;
		cout << endl;
		for (int i = 0; i < answer_chars.size(); i++) {
			for (int j = 0; j < answer_chars[i].size(); j++) {
				if (correct_letter_counter == num_output_correct_letters) cout << "_"; //If all correct letters have already been shown
				else {
					bool correct_letter = false;
					for (int k = 0; k < correct_letters.size(); k++) {
						if (answer_chars[i][j] == correct_letters[k]) { //Output correct letter
							cout << correct_letters[k];
							correct_letter = true;
							correct_letter_counter++;
							break;
						}
					}
					if (!correct_letter) cout << "_"; //Output _ to show space where letters are still needed
				}
			}
			cout << " ";
		}
		if (!incorrect_letters.empty()) { //Output letters to show which letters have been previously incorrectly guessed
			cout << "\nIncorrect guessed letters:\n";
			for (int i = 0; i < incorrect_letters.size(); i++) {
				cout << incorrect_letters[i];
				if (i != incorrect_letters.size() - 1) cout << ",\t";
			}
			cout << endl;
		}
	}
}