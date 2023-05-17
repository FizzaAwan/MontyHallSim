#include "monty.h"

#include <climits>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

static int get_n ();
static char get_strategy ();

int main () {

	// Initialize random number generator
	srand(time(0));

	// Get user's choice of strategy and number of test runs
	cout << "Testing monty function..." << endl << endl;
	int strategy = get_strategy();
	int test_runs = get_n();

	// Run tests and report results
	cout << "Contestant won " << monty(strategy, test_runs)
		<< " times." << endl;

#ifdef _MSC_VER
	system("pause");
#endif

	return 0;
}

// Prompt for and get number of test runs, with validation
static int get_n () {

	// Get number of test runs, must be positive
	int n;
	cout << "Enter number of test runs: ";
	cin >> n;

	// Validate input
	if (!cin || n < 1) {
		cout << "Invalid number of test runs. Try again.";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Enter number of test runs: ";
		cin >> n;
	}

	// Discard any remaining input
	cin.ignore(INT_MAX, '\n');

	return n;
}

// Prompt for and input strategy, with validation
static char get_strategy () {

	// Get strategy, must be 's', 'k', or 'r'.
	char strategy;
	cout << "Enter strategy (s, k, r): ";
	cin >> strategy;

	// Validate input
	while (strategy != 's' && strategy != 'k' && strategy != 'r') {
		cout << "Strategy is not valid. Try again." << endl;
		cin.ignore(INT_MAX, '\n');
		cin >> strategy;
	}

	// Discard any remaining input
	cin.ignore(INT_MAX, '\n');

	return strategy;
}