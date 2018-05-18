/*
 * Pizza.cpp
 *
 *  Created on: May 01 2018
 *  Author: PRINCE CLUMSON-EKLU
 *	EXAM # 1
 *	WSU ID # H888A642
 */

#ifndef PIZZA_ORDER_H_
#define PIZZA_ORDER_H_

#include <ostream>
#include <vector>

#include "MovieOrder.hpp"
#include "StringEnh.hpp"

class PizzaOrder {
public:
	// Static function to return movieorder's max number of pizzas
	static int getMaxNumberOfPizzas();

	// static function to return whether the number of movie is valid or not
	static bool isNumberOfPizzasValid(int numberOfPizzas);

	// Constructor default
	PizzaOrder();

	// Function to add a movie to the movie order
	void add(Pizza pizza);

	// Function to calculate and return movie order's total cost
	double calculateTotal() const;

	// Function to return true/false whether movie order is valid (initialized)
	bool isValid() const;

	// Function to return movie order as a string
	std::string toString() const;

	// Overloaded insertion operator <<
	friend std::ostream &operator <<(std::ostream &os, const PizzaOrder &pizzaOrder);

private:
	// Instance variables
	bool initialized;
	std::vector<Pizza> pizzas;
};

#endif /* PIZZA_ORDER_H_ */
