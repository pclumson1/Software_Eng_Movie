/*
 * MovieOrderDemo.cpp
 *  Created on: May 01, 2018
 *  Author: PRINCE CLUMSON-EKLU
 *	WSU ID # H888A642
 */

#include <iostream>
#include <time.h>

#include "Movie.hpp"
#include "MovieOrder.hpp"
#include "StringEnh.hpp"

void printTime();
using namespace std;

// Constants
static const string NO = "No";
static const string YES = "Yes";

/**
 * Prompt user for number of movies in order
 */
static int askForNumberOfPizzas()
{
	int numberOfPizzas = 0;
	string input;
	cout<<"*************************************************************************"<<endl;
	cout<<"**************************************************************************"<<endl;
	cout << "How many movies would you like to order ? (0-" << PizzaOrder::getMaxNumberOfPizzas() << ") [0]: ";
	getline(cin, input);
	if (!input.empty()) {
		int tempNumberOfPizzas = stoi(input);
		if (PizzaOrder::isNumberOfPizzasValid(tempNumberOfPizzas))
			numberOfPizzas = tempNumberOfPizzas;
	}

	return numberOfPizzas;
}

/**
 * Prompt user for pizza's pan size
 */
static Pizza::PanSize askForPanSize(int pizzaNumber)
{
	static const string INVALID = "Unrecognized movie type selected, try again.";
	static const string TRY_AGAIN = "No movie type  selected, do you want to try again? (Y/N) [Y]: ";

	Pizza::PanSize panSize = Pizza::UNKNOWN;
	string input;

	while (true) {
		cout << endl << "For movie " << pizzaNumber << ", what type would you like? <r>egular, <c>hildren, <n>ew release: ";
		getline(cin, input);
		if (!input.empty()) {
			Pizza::PanSize tempPanSize = Pizza::stringToPanSize(input);
			if (tempPanSize != Pizza::UNKNOWN) {
				panSize = tempPanSize;
				break;
			}
			cout << INVALID << endl;
		} else {
			cout << TRY_AGAIN;
			getline(cin, input);
			if (!input.empty()) {
				if (toupper(input[0]) == NO[0])
					break;
			}
		}
	}

	return panSize;
}

/**
 * Prompt user for number of additional days for rental.
 */
static int askForNumberOfCheeseToppings(int pizzaNumber)
{
	static const string INVALID = "Invalid number of additional days of renting, try again.";

	int numberOfToppings = 0;
	string input;

	while (true) {
		cout << endl;
		cout << "For movie" << pizzaNumber  << ", how many additional days of renting  would you like? (0-" << (Pizza::getMaxNumberOfCheeseToppings() - 2) << ") [0]: ";
		getline(cin, input);
		if (!input.empty()) {
			int tempNumberOfToppings = std::stoi(input);
			if (Pizza::isNumberOfCheeseToppingsValid(tempNumberOfToppings)) {
				numberOfToppings = tempNumberOfToppings;
				break;
			}
			cout << INVALID << endl;
		} else {
			if (Pizza::isNumberOfCheeseToppingsValid(numberOfToppings))
				break;
			cout << INVALID << endl;
		}
	}

	return numberOfToppings;
}

/**
 * Prompt user for a pizza order
 */
static PizzaOrder askForOrder()
{
	// Prompt for number of pizzas for this pizza order (limmited to the max allowed for an order)
	int numberOfPizzas = askForNumberOfPizzas();
	if (numberOfPizzas == 0)
	{
		exit(0);
	}
		

	// Start a new pizza order
	PizzaOrder order;

	// Prompt for each pizza's pan size and number of cheese toppings
	for (int i = 0; i < numberOfPizzas; i++) {
		// Compute which pizza this is
		int pizzaNumber = (i + 1) ;

		// Prompt for pan size
		Pizza::PanSize panSize = askForPanSize(pizzaNumber);
		if (panSize == Pizza::UNKNOWN)
			break;

		// Create pizza based on pan size and number of cheese toppings
		int numberOfToppings = askForNumberOfCheeseToppings(pizzaNumber);
		Pizza pizza = Pizza(panSize, numberOfToppings);

		// Add pizza to order
		order.add(pizza);
	}

	string costomer;
    cout<<"please enter your Name"<<endl;
    cin >> costomer;
    
	cout<<"***************************************************************"<<endl;
    printTime();
	cout<<"***************************************************************"<<endl;
	cout<<"***************************************************************"<<endl;
    cout<< costomer << " here is your movie rental receipt :"<<endl;
    printTime();
	cout<<"***************************************************************"<<endl;
	return order;
	//cout<<"***************************************************************"<<endl;
}

/**
 * Print a receipt for the movie order
 */
static void printReceipt(const PizzaOrder &order) {
	cout << order << endl;
}

/**
 * Main program
 */
int main()
{
	
    
	// Prompt for a movie order
	PizzaOrder order = askForOrder();

	// Print the movie order receipt
	printReceipt(order);
}



/*
 using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    
    return 0;
}
*/
void printTime()
{

	
    std::cout << "MOVIE RENTAL RECEIPT:!\n";
    
    time_t rawtime;
    struct tm * timeinfo;
    char buffer [80];
    
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    
    strftime (buffer, 80,"%Y-%m-%d at %H:%M:%S",timeinfo);
    puts (buffer);
    
    
}