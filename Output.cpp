//Program: Hangman
//This file contains the functions which output the problem and the hangman from C_Hangman.h

#include "C_Hangman.h"
#include <iostream>

void Display_Problem(vector<vector<char>> answer_words) {
	for (int i = 0; i < answer_words.size(); i++) {
		for (int j = 0; j < answer_words[i].size(); j++)
			cout << "_";
		(i + 1 < answer_words.size()) ? cout << " " : cout << "\n\n";
	}
}

void Display_Man(const int num_incorrect_guesses) {
	switch (num_incorrect_guesses) {
	case 0:
		cout << "\nAll lives remaining!\n\n__________\n";
		break;
	case 1:
		cout << "\n\n\t|\n\t|\n\t|\n\t|\n\t|\n\t|\n________|________\n";
		break;
	case 2:
		cout << "\n\t______\n\t|\n\t|\n\t|\n\t|\n\t|\n\t|\n________|________\n";
		break;
	case 3:
		cout << "\n\t______\n\t|    |\n\t|\n\t|\n\t|\n\t|\n\t|\n________|________\n";
		break;
	case 4:
		cout << "\n\t______\n\t|    |\n\t|    O\n\t|\n\t|\n\t|\n\t|\n________|________\n";
		break;
	case 5:
		cout << "\n\t______\n\t|    |\n\t|    O\n\t|    |\n\t|    |\n\t|    |\n\t|\n________|________\n";
		break;
	case 6:
		cout << "\n\t______\n\t|    |\n\t|    O\n\t|    |\n\t|  --|--\n\t|    |\n\t|\n________|________\n";
		break;

	case 7:
		cout << "\n\t______\n\t|    |\n\t|    O\n\t|    |\n\t|  --|--\n\t|    |\n\t|   /\n\t|  /\n________|________\n";
		break;
	case 8:
		cout << "\n\t______\n\t|    |\n\t|    O\n\t|    |\n\t|  --|--\n\t|    |\n\t|   / \\\n\t|  /   \\\n________|________\n";
	}
}