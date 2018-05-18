/*
 * Pizza.cpp
 *
 *  Created on: Mar 9, 2017
 *  Author: PRINCE CLUMSON-EKLU
 *	EXAM # 1
 *	WSU ID # H888A642
 */

#include <cstdio>
#include <ostream>
#include <iostream>

#include "MovieOrder.hpp"

/**
 *  STATIC CONSTANT NUMBER OF MOVIE
 */
static const int MAX_NUMBER_OF_PIZZAS = 3;

/**
 * FUNCTION TO ACCOMODATE THE MAX MOVIE ORDER.
 */
int PizzaOrder::getMaxNumberOfPizzas()
{
	return MAX_NUMBER_OF_PIZZAS;
}

/**
 * FUNCTION TO VALIDATE THE NUMBER OF MOVIES
 */
bool PizzaOrder::isNumberOfPizzasValid(int numberOfPizzas) {
	bool isValid = false;

	if (numberOfPizzas >= 1 && numberOfPizzas <= getMaxNumberOfPizzas())
		isValid = true;

	return isValid;
}

/**
 * DEFAULT CONSTRUCTOR
 */
PizzaOrder::PizzaOrder()
{
	// MovieOrder now initialized
	this->initialized = true;
}

/**
 * FUNCTION TO ADD MOVIES WITH A VECTOR
 */
void PizzaOrder::add(Pizza pizza)
{
	if ((int) pizzas.size() < MAX_NUMBER_OF_PIZZAS && pizza.isValid())
		pizzas.push_back(pizza);
}

/**
 * THIS FUNCTION CALCULATE AND RETURN THE TOTAL COST OF MOVIE ORDER.
 */
double PizzaOrder::calculateTotal() const
{
	double total = 0.0;

	// Compute total based on accumulating cost of each MOVIE
	for (int i = 0; i < (int) pizzas.size(); i++) {
		total += pizzas[i].calculateCost();
	}

	return total;
}

/**
 * Function to return true/false whether MOVIE order is valid (initialized)
 */
bool PizzaOrder::isValid() const
{
	return initialized;
}

/**
 * Function to return movie order as a string
 */
std::string PizzaOrder::toString() const
{
	
	std::string receipt = "Thank you for your order.\n\n";

	// Generate a string based on the order placed
	bool firstTime = true;
	for (int i = 0; i < (int) pizzas.size(); i++) {
		if (firstTime) {
			firstTime = false;
			receipt += "Your order includes:\n\n";
		}
		receipt += pizzas[i].toString() + "\n\n";
	}
	if (firstTime) {
		receipt += "You haven't ordered any movies.";
	} else {
		char str[200];
		sprintf(str, "Total due: $%.2f", calculateTotal());
		
		receipt += str;
	}

	return receipt;
}

/**
 * Overloaded insertion operator <<
 */
std::ostream &operator <<(std::ostream &os, const PizzaOrder &pizzaOrder)
{
	// Output formatted string
	os << pizzaOrder.toString();

	return os;
}
