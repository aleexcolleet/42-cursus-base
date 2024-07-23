#include <iostream>

int main()
{
	std::cout << "\033[1;34m" << std::endl;  // Bold Blue
	std::cout << " _____ _               _____         _   "  << std::endl;
    std::cout << "|  _  | |_ ___ ___ ___| __  |___ ___| |_  " << std::endl;
    std::cout << "|   __|   | . |   | -_| __ -| . | . | '_| " << std::endl;
    std::cout << "|__|  |_|_|___|_|_|___|_____|___|___|_,_|" << std::endl;
    std::cout << "\033[0m" << std::endl;  // Reset color

    std::cout << "\033[1;33m--------------USAGE---------------\033[0m" << std::endl;  // Bold Yellow
    std::cout << "\033[1;36mADD\t: To add a contact.\033[0m" << std::endl;  // Bold Cyan
    std::cout << "\033[1;36mSEARCH\t: To search for a contact.\033[0m" << std::endl;
    std::cout << "\033[1;36mEXIT\t: To quit the PhoneBook.\033[0m" << std::endl;
    std::cout << "\033[1;33m----------------------------------\033[0m" << std::endl;
    std::cout << std::endl;
}
