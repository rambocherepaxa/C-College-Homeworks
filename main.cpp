#include <iostream>
#include "ShoeStore.h"
#define ADD_SHOES 1
#define DELETE_PAIR 2
#define CHECK_DISCOUNT 3
#define CHANGE_DISCOUNT 4
#define CHECK_AVERAGE_PRICE 5
#define CHECK_SHOE_PRICE 6
#define PRINT_STORAGE_PAIRS 7
#define EXIT 8

void PrintMenu();

int main()
{
    ShoeStore current_shoe_store;
    bool using_program = true;
    int user_option = 0, user_pair_price = 0, user_count_of_pairs = 0,
    user_current_discount = 0; 
    std::string user_name_pair = "";

    std::cout << "Welcome! \n \n This program will help you find your way around a shoe store more easily. In this program you have different options to get information about shoes or change them." << std::endl;
    while (using_program)
    {
        PrintMenu();
        std::cin >> user_option;

        switch (user_option) 
        {
        case ADD_SHOES:
            std::cout << "Enter pair name: ";
            std::cin >> user_name_pair;
            std::cout << "Enter pair price: ";
            std::cin >> user_pair_price;
            while (user_pair_price <= 0)
            {
                std::cout << "\nPrice must be more than 0.\nEnter again: ";
                std::cin >> user_pair_price;
            }   
            std::cout << "Enter number of pairs: ";
            std::cin >> user_count_of_pairs;
            while (user_count_of_pairs <= 0)
            {
                std::cout << "\nPairs count must be more than 0.\nEnter again: ";
                std::cin >> user_count_of_pairs;
            }
            current_shoe_store.AddShoes(user_name_pair, user_pair_price, user_count_of_pairs);
            std::cout << "\n*Thanks for update!*\n";
            break;
        case DELETE_PAIR:
            std::cout << "Enter pair name: ";
            std::cin >> user_name_pair;
            std::cout << "\n*Thanks for update!*\n";
            break;
        case CHECK_DISCOUNT:
            std::cout << "Current discount is: "
                << current_shoe_store.GetDiscountPercent();
            break;
        case CHANGE_DISCOUNT:
            std::cout << "Enter new discount (in procents): ";
            std::cin >> user_current_discount;
            while (user_current_discount < 0 || user_current_discount > 100)
            {
                std::cout << "Discount must be between 0 and 100: ";
                std::cin >> user_current_discount;
            }
            current_shoe_store.SetDiscountPercent(user_current_discount);
            std::cout << "\n*Thanks for update!*\n";
            break;
        case CHECK_AVERAGE_PRICE:
            std::cout << "Current average price is: " << current_shoe_store.AverageShoePrice();
            break;
        case CHECK_SHOE_PRICE:
            std::cout << "Enter pair name: ";
            std::cin >> user_name_pair;
            std::cout << "Pair price is: " << current_shoe_store.GetShoePrice(user_name_pair);
        case PRINT_STORAGE_PAIRS:
            current_shoe_store.PrintAllPairs();
            break;
        case EXIT:
            using_program = false;
            break;
        default:
            std::cout << "\nInvalid option!\nChoose only 1-7: " << std::endl;
            break;
        }
    }

    std::cout << "See you later, Bye!! :)\n\n";
    
    system("pause");
}

void PrintMenu()
{
    std::cout << "\n1) Add shoes pair\n2) Delete shoes pair\n\n3) Show discount\n4) Change discount\n\n5) Check average price\n6) Check shoe price\n\n7) Show all shoes in storage\n8) Exit\n\nChoose your option:  ";
}