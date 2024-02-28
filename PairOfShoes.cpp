#include "PairOfShoes.h"

int PairOfShoes::getPrice() const
{ return _price; }

std::string PairOfShoes::getName() const
{ return _name_pair; }

void PairOfShoes::setPrice(float new_price)
{_price = new_price;}


PairOfShoes::PairOfShoes(std::string name_pair, float price)
{
	this->_name_pair = name_pair;
	this->_price = price;
}

PairOfShoes::PairOfShoes(){
}

PairOfShoes::PairOfShoes(PairOfShoes& pair) :
	PairOfShoes(pair._name_pair, pair._price)
{
		
}
