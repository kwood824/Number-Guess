#include <iostream>

using namespace std;

int main()
{
	char game;
	game = 'Y';
	const char Y = 'Y';
	const char N = 'N';
	while ((game == 'Y') || (game == 'y'))
	{
		int number;
		cout << "Player 1 please type a number between 1 and 10" << endl;
		cin >> number;
		int guesses, lowValue, highValue;
		guesses = 3;
		lowValue = 1;
		highValue = 10;
		if ((number < 1) || (number > 10))
		{
			cout << "ERROR. Please select a number between 1 and 10" << endl;
			continue;
		}
		while (guesses > 0)
		{

		
			if ((number >= lowValue) && (number <= highValue))
			{
				int guess;
				cout << "Player 2 please guess Player 1's number (between " << lowValue << " and " << highValue << ") you have " << guesses << " tries left" << endl;
				cin >> guess;
				if ((guess < lowValue) || (guess > highValue))
				{
					cout << "ERROR. Please select a number between " << lowValue << " and " << highValue << endl;
				}
				if ((guess >= lowValue) && (guess < number))
				{
					lowValue = guess;
				}
				if ((guess < number) && (guess >= lowValue))
				{
					cout << "Sorry, your guess is less than Player 1's number" << endl;
					guesses = guesses - 1;
				}
				if ((guess <= highValue) && (guess > number))
				{
					highValue = guess;
				}
				if ((guess <= highValue) && (guess > number))
				{
					cout << "Sorry, your guess is more than Player 1's number" << endl;
					guesses = guesses - 1;
				}
				if (guess == number)
				{
					cout << "Congratulations! You guessed correctly! Player 2 Wins!" << endl;
					break;
				}
				if (guesses <= 0)
				{
					cout << "You failed to guess correctly in time! Player 1 Wins!" << endl;
					if (guess < number)
					{
						cout << "The correct number was " << number << "! You were " << number - guess << " off!" << endl;
					}
					if (guess > number)
					{
						cout << "The correct number was " << number << "! You were " << guess - number << " off!" << endl;
					}
				}

			}
		}
			cout << "Would you like to play again Y/N?" << endl;
			cin >> game;
	}


	if ((game == 'N') || (game == 'n'))
	{
		cout << "Thanks for playing!";
	}

	cin.get();
	cin.get(); // I added these two to make the executable pause before closing when I compile at home

	return 0;
}