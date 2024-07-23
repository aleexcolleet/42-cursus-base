#include <iostream>
#include <limits>
#include "PhoneBook.hpp"

int main(){
    PhoneBook book;
    std::string input = "";
    book.welcome();
    while (input.compare("EXIT")){
        if (input.compare("ADD") == 0)
            book.addContact();
        else if (input.compare("SEARCH") == 0){
            book.printContacts();
            book.search();
        }
        std::cout << "  ." << std::endl;
        std::cout << " ..^____/" << std::endl;
        std::cout << "`-. ___ )" << std::endl;
        std::cout << " ||  || mh" << std::flush;
        std::cin >> input;
    }
    return (0);
}