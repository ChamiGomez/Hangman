//Program: Hangman
//This file contains the C_Hangman class declaration and the declarations of output data functions used in the program

#pragma once
#include <vector>
#include <string>

using namespace std;

class C_Hangman {
public:
	vector<vector<char>> answer_chars;
	vector<char> letters, correct_letters, incorrect_letters;
	vector<int> letter_uses;
	int num_incorrect_guesses = 0, num_output_correct_letters = 0;

	void Generate_Answer(void);
	void Process_Problem(void);
	void Process_Guess(const char guessed_letter);
	void Display_Status(void);
};

void Display_Problem(vector<vector<char>> answer_words);
void Display_Man(const int num_incorrect_guesses);