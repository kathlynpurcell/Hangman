#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
//idea from http://www.cppforschool.com/project/hangman-game-code.html

int main() {

	std::string word;
	int tries = 1;
	int max_tries = 6;
	char guess;
	int size;
	int fill_in(char, std::string, int, std::string);

	std::fstream myfile;
	myfile.open("words.txt");

	srand((unsigned)time(0)); //srand makes it truly random
	int number = (rand() % 100) + 1;

	for (int i = 0; i < number; i++) //gets the random word from the text file
		std::getline(myfile, word);

	size = word.length();
	std::string newWord;
	newWord.resize(size, '*');
	std::cout << "Welcome to Hangman! Here are the rules:" << std::endl;
	std::cout << "Try to guess a randomly generated word." << std::endl;
	std::cout << "You have 6 tries (body, legs, arms, head) and each time you can guess only 1 letter" << std::endl;
	std::cout << "Good Luck!" << std::endl;

	while (tries < max_tries) {
		std::cout << "\n\n" <<"This is your current word: " << newWord << std::endl;
		std::cout << "What is your guess? You have " << max_tries-tries << " tries left." << std::endl;
		std::cin >> guess;

		int i;
		for (i = 0; i < size; i++) {
			if (guess == word[i]) {
				newWord[i] = guess;
			}
		}

		if (word == newWord) {
			std::cout << "You did it! The word was " << word << "!";
			break;
		}

		if (fill_in(guess, word, size, newWord) == 0)  {
			std::cout << "Thats not in there.";
			tries = tries + 1;
			}

		else {
			std::cout << "You guessed a letter! Pick another.";
		}
		
	}
	std::cout << "The word was: \n\n" << word;

	return 0;
}

int fill_in(char guess, std::string word, int size, std::string newWord) {
	int correct = 0;
	int i;
	for (i = 0; i < size; i++) {
		if (guess == word[i]) {
			newWord[i] = guess;
			correct = correct + 1;
		}
	}
	return correct;
}