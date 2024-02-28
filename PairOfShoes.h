#pragma once
#include <iostream>

class PairOfShoes
{

private:
	std::string _name_pair = "";
	float _price = 0;

public:

// Methods___________________________________________________________________________________
	PairOfShoes(std::string name_pair, float price);
	PairOfShoes(); // empty constructor for storage array
	PairOfShoes(PairOfShoes& pair);


	// Getters___________________________________________________________________________________
	int getPrice() const;
	std::string getName() const;

	// Setters___________________________________________________________________________________
	void setPrice(float new_price);
	
//___________________________________________________________________________________
};

