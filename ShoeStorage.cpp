#include "ShoeStorage.h"

ShoeStorage::ShoeStorage(int size)
{
	this->_pairs_storage = new PairOfShoes * [size];
	
	for (int i = 0; i <= size; i++)
		this->_pairs_storage[i] = nullptr;

	this->_size_storage = size;
	this->_count_of_shoes = 0;
}


ShoeStorage& ShoeStorage::operator=(const ShoeStorage& other)
{
	// free memory allocated for the current shoes
	for (int i = 0; i < _count_of_shoes; i++)
	{
		delete _pairs_storage[i];
	}
	delete[] _pairs_storage;

	// copy the other shoes
	_count_of_shoes = other._count_of_shoes;
	_pairs_storage = new PairOfShoes * [_count_of_shoes];
	for (int i = 0; i < _count_of_shoes; i++)
	{
		_pairs_storage[i] = other._pairs_storage[i];
	}

	return *this;
}

// Copy Constructor
ShoeStorage::ShoeStorage(const ShoeStorage& other)
{
	// copy the other shoes
	_count_of_shoes = other._count_of_shoes;
	_pairs_storage = new PairOfShoes * [_count_of_shoes];
	for (int i = 0; i < _count_of_shoes; i++)
	{
		_pairs_storage[i] = other._pairs_storage[i];
	}
}

// Destructor
ShoeStorage::~ShoeStorage()
{
	// free memory allocated for the shoes
	for (int i = 0; i < _count_of_shoes; i++)
	{
		delete _pairs_storage[i];
	}
	delete[] _pairs_storage;
}




void ShoeStorage::AddPairOfShoes(PairOfShoes& new_pair)
{
	// Duplicate place if storage full
	if (this->_count_of_shoes == this->_size_storage)
	{
		// creating new storage
		this->_size_storage *= 2;
		PairOfShoes** new_storage = new PairOfShoes * [this->_size_storage];

		// saving prev info from full storage
		for (int i = 0; i < this->_count_of_shoes; i++) 
			new_storage[i] = this->_pairs_storage[i];
		
		// free prev storage
		delete[] this->_pairs_storage;

		// saving new storage
		this->_pairs_storage = new_storage;
	}

	//creating new free places in storage
	for (int i = this->_count_of_shoes; i < this->_size_storage; i++)
		this->_pairs_storage[i] = nullptr;

	// Add new pair  ******** SOME PROBLEM HERE *********
	this->_pairs_storage[this->_count_of_shoes] = new PairOfShoes(new_pair);
	//this->_pairs_storage++;
	this->_count_of_shoes++;
}


float ShoeStorage::GetPrice(std::string pair_name)
{
	// searching pair by name
	for (int i = 0; i < this->_count_of_shoes; i++)
	{
		// if name found - return price of pair
		if (this->_pairs_storage[i]->getName() == pair_name)
		{
			return this->_pairs_storage[i]->getPrice();
		}
	}
	return 0;
}

float ShoeStorage::AverageShoePrice()
{
	float avg_price = 0;
	for (int i = 0; i < this->_count_of_shoes; i++)
	{
		avg_price += this->_pairs_storage[i]->getPrice();
	}
	return avg_price / this->_count_of_shoes;
}

void ShoeStorage::RemovePairOfShoes(std::string pair_name)
{
	//search by name
	int index = -1;
	for (int i = 0; i < this->_count_of_shoes; i++) {
		if (this->_pairs_storage[i]->getName() == pair_name) 
		{
			index = i;
			break;
		}
	}

	// if found - delete
	if (index != -1) {
		delete this->_pairs_storage[index];

		// move all items left to free place
		for (int i = index; i < this->_count_of_shoes - 1; i++) {
			this->_pairs_storage[i] = this->_pairs_storage[i + 1];
		}

		// updating current pairs count
		this->_count_of_shoes--;
	}
}

void ShoeStorage::PrintShoePairs()
{
	std::cout << "\n";
	for (int i = 0; i < this->_count_of_shoes; i++) {
		std::cout << "Pair name: " << this->_pairs_storage[i]->getName() << " | price: ";
		std::cout << this->_pairs_storage[i]->getPrice() << std::endl;
	}
	std::cout << "\n";
}

