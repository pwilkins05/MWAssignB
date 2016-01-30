#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <string>

/*******************************
*
* Yahtzee
*
* Starter code by Paul Wilkins
* Last Modified: 02/04/2014
*
*******************************/

// TODO: switch to using arrays for scores -- See below
// TODO switch to using array for dice -- Done - DJ
// TODO: add yahtzee bonus score -- Done - DJ
// TODO: implement scoring functions (see switch statement, line 125) -- Done - DJ
// TODO: make ask reroll accept lowercase letters -- Done - DJ
// BUG: dice not holding correct values -- Fixed dice roll so 1-6 is returned instead of 0-5 - DJ

using namespace std;

void printRoll(int n[]);
bool askReroll(int n);
void printSeparator();
void printScore(int onesScore, int twosScore, int threesScore, int foursScore,
	int fivesScore, int sixesScore, int threeOfAKind,
	int fourOfAKind, int fullHouse, int smallStraight,
	int largeStraight, int yahtzee, int chance);
void printScoreLine(string name, int score);
int getScoreOption(int onesScore, int twosScore, int threesScore, int foursScore,
	int fivesScore, int sixesScore, int threeOfAKind,
	int fourOfAKind, int fullHouse, int smallStraight,
	int largeStraight, int yahtzee, int chance);
int tabulateDice(int n, int d[]);
int sumOfDice(int d[]);

const int NUM_CATEGORIES = 13;
const int SIDES = 6;
const int EMPTY = -1;
enum Category {
	ONES = 1, TWOS, THREES, FOURS, FIVES, SIXES, THREE_OF_A_KIND,
	FOUR_OF_A_KIND, FULL_HOUSE, SMALL_STRAIGHT, LARGE_STRAIGHT,
	YAHTZEE, CHANCE
};

int main()
{

	int die[5]; // changed die and redo to arrays - DJ
	bool redo[5];

	int ones, twos, threes, fours, fives, sixes;

	/* Need to convert int scores to an associative int array */
	int onesScore, twosScore, threesScore, foursScore, fivesScore, sixesScore;
	int threeOfAKind;
	int fourOfAKind;
	int fullHouse;
	int smallStraight;
	int largeStraight;
	int yahtzee;
	int chance;

	onesScore = twosScore = threesScore = foursScore = fivesScore = sixesScore = EMPTY;
	threeOfAKind = fourOfAKind = fullHouse = smallStraight = largeStraight = yahtzee = chance = EMPTY;

	cout << "Welcome to Yahtzee!" << endl;
	srand(time(0));



	for (int turn = 0; turn < NUM_CATEGORIES; turn++)
	{
		int round = 1;
		ones = twos = threes = fours = fives = sixes = 0;
		for (int x = 0; x < 5; x++) {
			die[x] = rand() % SIDES + 1;
		}
		printRoll(die); /* Changed die to array - DJ */
		do
		{  // made redo an array

			for (int x = 0; x < 5; x++) {
				redo[x] = askReroll(x+1);
				if (redo[x]) die[x] = rand() % SIDES + 1;
			}

			printRoll(die); /* Changed die to array - DJ */
			round++;
		} while ((redo[1] || redo[2] || redo[3] || redo[4] || redo[5]) && round < 3);

		ones = tabulateDice(1, die); // edited function call to use die array - DJ
		twos = tabulateDice(2, die);
		threes = tabulateDice(3, die);
		fours = tabulateDice(4, die);
		fives = tabulateDice(5, die);
		sixes = tabulateDice(6, die);

		int scoreOption = getScoreOption(onesScore, twosScore, threesScore, foursScore,
			fivesScore, sixesScore, threeOfAKind,
			fourOfAKind, fullHouse, smallStraight,
			largeStraight, yahtzee, chance);

		switch (scoreOption)
		{
		case ONES:
			onesScore = ones;
			break;
		case TWOS:
			twosScore = twos * 2;
			break;
		case THREES:
			threesScore = threes * 3;
			break;
		case FOURS:
			foursScore = fours * 4;
			break;
		case FIVES:
			fivesScore = fives * 5;
			break;
		case SIXES:
			sixesScore = sixes * 6;
			break;
		case THREE_OF_A_KIND:
			threeOfAKind = sumOfDice(die);
			break;
		case FOUR_OF_A_KIND:
		fourOfAKind = sumOfDice(die);
		break;
		case FULL_HOUSE:
		fullHouse= 25;
		break;
		case SMALL_STRAIGHT:
		smallStraight = 30;
		break;
		case LARGE_STRAIGHT:
		largeStraight = 40;
		break;
		case YAHTZEE:
			if (yahtzee == 50) yahtzee = 150; /* Added Yahtzee bonus - DJ */
			else yahtzee = 50;
		yahtzee = 50;
		break;
		case CHANCE:
		chance = sumOfDice(die);
		break;
		}

		

		printScore(onesScore, twosScore, threesScore, foursScore, fivesScore, sixesScore,
			threeOfAKind, fourOfAKind, fullHouse, smallStraight, largeStraight, yahtzee, chance);
	}
}

int sumOfDice(int d[])
{
	int sum = 0;
	for (int x = 0; x < 5; x++) {
		sum += d[x];
	}
	return sum;
}

/*********************************************************
*
* printRoll
* ------------------
* This function prints out the current state of the dice,
* with blank lines before and after the print-out.
*
*********************************************************/
void printRoll(int n[]) /* Changed die to array - DJ */
{
	cout << endl;
	cout << "Your roll is:" << endl;
	for (int x = 0; x < 5; x++) {
		cout << n[x] << " ";
	}
	cout << endl << endl;
}

/*********************************************************
*
* askReroll
* ------------------
* This function ask the user if they'd like to reroll one
* one of the dice.  The function takes an integer which is
* the number of the die being rerolled, and returns true if
* the die should be rerolled, false otherwise.  The integer
* argument is used only for instruction display, this function
* does not actually reroll any dice.  Responses accepted are
* 'Y' and 'N'.
*
*********************************************************/
bool askReroll(int n)
{
	char ch;
	while (true)
	{
		cout << "Would you like to reroll die " << n << "? (Y/N) ";
		cin >> ch;
		switch (ch)
		{
		case 'Y':
			return true;
		case 'N':
			return false;
		case 'y':  // Added lowercase y/n cases - DJ
			return true;
		case 'n':
			return false;
		default:
			cout << "Invalid response" << endl;
		}
	}

}



/********************************
*
* printScore
* --------------------
* This function prints out the complete score table
* for the yahtzee game in its current state.
*
********************************/
void printScore(int onesScore, int twosScore, int threesScore, int foursScore,
	int fivesScore, int sixesScore, int threeOfAKind,
	int fourOfAKind, int fullHouse, int smallStraight,
	int largeStraight, int yahtzee, int chance)
{
	printSeparator();
	printScoreLine("Ones", onesScore);
	printSeparator();
	printScoreLine("Twos", twosScore);
	printSeparator();
	printScoreLine("Threes", threesScore);
	printSeparator();
	printScoreLine("Fours", foursScore);
	printSeparator();
	printScoreLine("Fives", fivesScore);
	printSeparator();
	printScoreLine("Sixes", sixesScore);
	printSeparator();
	printScoreLine("Three of a kind", threeOfAKind);
	printSeparator();
	printScoreLine("Four of a kind", fourOfAKind);
	printSeparator();
	printScoreLine("Full House", fullHouse);
	printSeparator();
	printScoreLine("Small Straight", smallStraight);
	printSeparator();
	printScoreLine("Large Straight", largeStraight);
	printSeparator();
	printScoreLine("Yahtzee", yahtzee);
	printSeparator();
	printScoreLine("Chance", chance);
	printSeparator();
}

/********************************
*
* printSeperator
* --------------------
* This helper function prints out a single
* separator line used as part of the score
* printing function.
*
********************************/
void printSeparator()
{
	cout << "+-------------------+-------+" << endl;
}

/********************************
*
* printScoreLine
* --------------------
* This function prints out a single line of the score.
* The string argument is the name of the category, while
* the in is the value of the score.  The category name is left
* aligned, while the score value is right aligned.
*
********************************/
void printScoreLine(string name, int score)
{
	cout << "| " << left << setw(18) << name << "| ";
	if (score >= 0)
	{
		cout << right << setw(5) << score;
	}
	else
	{
		cout << "     ";
	}
	cout << " |" << endl;
}

/********************************
*
* getScoreOption
* --------------------
* This function gets the score category which the player wishes to score
* with the current roll.  The function ensures that the response corresponds
* to a valid category.  It also check to make sure that the selected category
* has not yet been scored (unscored categories contain the value EMPTY).
*
********************************/
int getScoreOption(int onesScore, int twosScore, int threesScore, int foursScore,
	int fivesScore, int sixesScore, int threeOfAKind,
	int fourOfAKind, int fullHouse, int smallStraight,
	int largeStraight, int yahtzee, int chance)
{
	int ans;
	bool valid = false;
	cout << "Here are the categories: " << endl;
	cout << "1. Ones" << endl;
	cout << "2. Twos" << endl;
	cout << "3. Threes" << endl;
	cout << "4. Fours" << endl;
	cout << "5. Fives" << endl;
	cout << "6. Sixes" << endl;
	cout << "7. Three of a kind" << endl;
	cout << "8. Four of a kind" << endl;
	cout << "9. Full House" << endl;
	cout << "10. Small Straight" << endl;
	cout << "11. Large Straight" << endl;
	cout << "12. Yahtzee" << endl;
	cout << "13. Chance" << endl;
	do
	{
		cout << "How would you like to score this? ";
		cin >> ans;
		while (ans < 0 || ans > NUM_CATEGORIES)
		{
			cout << "Please enter a number between 1 and " << NUM_CATEGORIES << ": ";
			cin >> ans;
		}
		switch (ans)
		{
		case ONES:
			if (onesScore == EMPTY) valid = true;
			break;
		case TWOS:
			if (twosScore == EMPTY) valid = true;
			break;
		case THREES:
			if (threesScore == EMPTY) valid = true;
			break;
		case FOURS:
			if (foursScore == EMPTY) valid = true;
			break;
		case FIVES:
			if (fivesScore == EMPTY) valid = true;
			break;
		case SIXES:
			if (sixesScore == EMPTY) valid = true;
			break;
		case THREE_OF_A_KIND:
			if (threeOfAKind == EMPTY) valid = true;
			break;
		case FOUR_OF_A_KIND:
			if (fourOfAKind == EMPTY) valid = true;
			break;
		case FULL_HOUSE:
			if (fullHouse == EMPTY) valid = true;
			break;
		case SMALL_STRAIGHT:
			if (smallStraight == EMPTY) valid = true;
			break;
		case LARGE_STRAIGHT:
			if (largeStraight == EMPTY) valid = true;
			break;
		case YAHTZEE:
			if (yahtzee == 50 || yahtzee == EMPTY) valid = true; /* Added Yahtzee bonus - DJ */
			break;
		case CHANCE:
			if (chance == EMPTY) valid = true;
			break;
		}
		if (!valid)
		{
			cout << "That category has already been used" << endl;
		}
	} while (!valid);

	return ans;
}

/********************************
*
* tabulateDice
* --------------------
* This function calculates and returns the number of dice
* which show the value n.
*
********************************/
int tabulateDice(int n, int d[]) /* Changed function to take die array - DJ */
{
	int ans = 0;
	for (int x = 0; x < 5; x++) {
		if (d[x] == n) ans++;
	}
	return ans;
}
