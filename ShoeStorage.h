#pragma once
#include <iostream>
#include "PairOfShoes.h"

#define STORAGE_DEFAULT_SIZE 4

class ShoeStorage {
   
private:

    PairOfShoes** _pairs_storage;

    int _count_of_shoes, _size_storage;

// Methods___________________________________________________________________________________

public:
    ShoeStorage(int size = STORAGE_DEFAULT_SIZE);
    ~ShoeStorage();

    // Assignment Operator
    ShoeStorage& operator=(const ShoeStorage& other);
    // Copy Constructor
    ShoeStorage(const ShoeStorage& other);


    void AddPairOfShoes(PairOfShoes& new_pair);
    void RemovePairOfShoes(std::string pair_name);
    float GetPrice(std::string pair_name);
    float AverageShoePrice();

    //extra 
    void PrintShoePairs();

};


