/*
 * Movie.hpp
 *  Created on: Mar May 1st.
 *  Author: PRINCE CLUMSON-EKLU
 */

#ifndef PIZZA_H_ 
#define PIZZA_H_ 

#include <ostream>
#include <string>
#include "StringEnh.hpp"

/**
 * The Movie class identifies properties of a movie.
 **/
class Pizza { 
public:
	// Enumerated type of Pizza available for the customer.
	enum PanSize { UNKNOWN, SMALL, MEDIUM, LARGE };

	// Static function to return pizza's price for a small
	static double getPriceSmall();

	// Static function to return pizza's price for a medium
	static double getPriceMedium();

	// Static function to return pizza's price for a large
	static double getPriceLarge();

	// Static function to return pizza's max number of cheese toppings
	static int getMaxNumberOfCheeseToppings();

	// Function to cast pizza's pan size from type string to PanSize
	static PanSize stringToPanSize(std::string str);

	// Static function to return pizza's pan size as a string
	static std::string panSizeToString(PanSize panSize);

	// Static function to validate pizza's pan size
	static bool isPanSizeValid(char c);

	// Static function to validate pizza's pan size
	static bool isPanSizeValid(std::string panSize);

	// Static function to validate pizza's number of cheese toppings
	static bool isNumberOfCheeseToppingsValid(int numberCheeseToppings);

	// Constructor default
	Pizza();

	// Constructor allowing caller to specify a pizza's pan size and number of cheese toppings
	Pizza(PanSize panSize, int numberOfCheeseToppings);

	// Accessor to return pizza's pan size
	PanSize getPanSize() const;

	// Accessor to return pizza's number of cheese toppings
	int getNumberOfCheeseToppings() const;

	// Function to calculate and return pizza's cost
	double calculateCost() const;

	// Function to return true/false whether pizza is valid (initialized)
	bool isValid() const;

	// Function to return pizza as a string
	std::string toString() const;

	// Overloaded insertion operator <<
	friend std::ostream &operator <<(std::ostream &os, const Pizza &pizza);

private:
	// Instance variables
	bool initialized;
	PanSize panSize;
	int numberOfCheeseToppings;
};

#endif /* PIZZA_H_ */
