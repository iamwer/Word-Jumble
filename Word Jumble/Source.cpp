#include <iostream>
#include <random>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{	
	enum field {WORD, HINT, NUM_FIELDS};
	const int NUM_WORDS = 5;
	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
		{"wall", "Do you feel you're banging your head against something?"},
		{"glasses", "These might help you see the answer."},
		{"labored", "Going slowly, is it?"},
		{"persistent", "Keep at it,"},
		{"jumble", "It's what the game is all about"}
	};


	srand(static_cast<unsigned int>(time(0)));
	int choice = (rand() % NUM_WORDS);
	string theWord = WORDS[choice][WORD];
	string theHint = WORDS[choice][HINT];


	string jumble = theWord;
	int lenght = jumble.size();
	for (int i = 0; i < lenght; i++)
	{
		int index1 = (rand() % lenght);
		int index2 = (rand() % lenght);
		char temp = jumble[index1];
		jumble[index1] = jumble[index2];
		jumble[index2] = temp;
	}

	cout << "\t\t\tWelcome to Word Jumble!\n\n";
	cout << "Unscramle the letters to make a word.\n";
	cout << "Enter hint for a hint.\n";
	cout << "Enter 'quit' to quit the game.\n\n";
	cout << "The Jumble is: " << jumble;
	string guess;
	cout << "\n\nYour guess: ";
	cin >> guess;

	while ((guess != theWord) && (guess != "quit"))
	{
		if (guess == "hint")
		{
			cout << theHint;
		}
		else
		{
			cout << "Sorry, that's not it.";
		}
		cout << "\n\nYour guess: ";
		cin >> guess;
	}

	if (guess == theWord)
	{
		cout << "\nThat's it! You guessed it!\n";
	}

	cout << "\nThanks for playing.\n";





	return 0;
}