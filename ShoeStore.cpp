#include "ShoeStore.h"

ShoeStore::ShoeStore(float discount_percentage)
{
	if (discount_percentage != 0)
	{
		this->_discount_percentage = discount_percentage;
		return;
	}		
}

ShoeStore::~ShoeStore()
{
	this->_discount_percentage = 0;
}

float ShoeStore::GetDiscountPercent()
{
	return this->_discount_percentage;
}

void ShoeStore::SetDiscountPercent(float new_discount_percent)
{
	this->_discount_percentage = new_discount_percent;
}

void ShoeStore::AddShoes(std::string new_pair_name, float new_pair_price, int count_of_pairs)
{
	for (int i = 0; i < count_of_pairs; i++)
	{
		// creating new pair              |                   
		PairOfShoes new_pair(new_pair_name, new_pair_price);
		
		// add new pair in storage
		this->_store_storage.AddPairOfShoes(new_pair);
	}
}

float ShoeStore::AverageShoePrice()
{
	// (condition) ? if ture : if false; 
	return (this->_store_storage.AverageShoePrice() != 0) ? // avg will be 0 if no shoes in storage
		this->_store_storage.AverageShoePrice() - // calculating discount of avg price
		(this->_store_storage.AverageShoePrice() * (this->_discount_percentage / 100)) 
		: 0 ; // return 0 if no shoes in storage
}

float ShoeStore::GetShoePrice(std::string pair_name)
{
	return this->_store_storage.GetPrice(pair_name) -
		(this->_store_storage.GetPrice(pair_name) * (this->_discount_percentage / 100));
}

void ShoeStore::RemoveOnePair(std::string pair_name)
{
	this->_store_storage.RemovePairOfShoes(pair_name);
}

void ShoeStore::PrintAllPairs()
{
	this->_store_storage.PrintShoePairs();
}


