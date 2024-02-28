#pragma once
#include <iostream>
#include "PairOfShoes.h"
#include "ShoeStorage.h"

class ShoeStore
{
private:

	ShoeStorage _store_storage;

	float _discount_percentage = 0;



	// Methods___________________________________________________________________________________
public:
	ShoeStore(float discount_percentage = 0);
	~ShoeStore();

	// getters and setters
	float GetDiscountPercent();
	void SetDiscountPercent(float new_discount_percent);

	// other methods
	void AddShoes(std::string new_pair_name, float new_pair_price, int count_of_pairs = 1);
	float AverageShoePrice();
	float GetShoePrice(std::string pair_name);
	void RemoveOnePair(std::string pair_name);
	void PrintAllPairs();
};


