//Program: Hangman
//This file contains the function for inputting the solution for the game from C_Hangman.h

#include "C_Hangman.h"
#include <iostream>
#include <sstream>
#include <locale>
#include <conio.h>

void C_Hangman::Generate_Answer(void) {
	char ch = 'a';
	int word_counter = 0;
	answer_chars.resize(1);
	cout << "Please enter answer (press 'Enter' to finish): ";
	do {
		ch = _getch();
		if (ch == '\r') return; //_getch() returns \r not \n for 'Enter' on keybaord
		else if (ch == ' ') {
			word_counter++;
			answer_chars.resize(answer_chars.size() + 1);
			cout << " ";
		}
		else {
			answer_chars[word_counter].push_back(toupper(ch));
			cout << "*";
		}
	} while (ch != '\r'); //Never actually reached due to return
}