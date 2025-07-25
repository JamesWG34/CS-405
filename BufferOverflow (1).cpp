// BufferOverflow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <iostream>

int main()
{
    std::cout << "Buffer Overflow Example" << std::endl;

    // TODO: The user can type more than 20 characters and overflow the buffer, resulting in account_number being replaced -
    //  even though it is a constant and the compiler buffer overflow checks are on.
    //  You need to modify this method to prevent buffer overflow without changing the account_number
    //  variable, and its position in the declaration. It must always be directly before the variable used for input.
    //  You must notify the user if they entered too much data.

    const std::string account_number = "CharlieBrown42";
    char user_input[20];

    std::cout << "Enter a value: ";

    // NEW: Limit input to sizeof(user_input)-1 characters to prevent overflow
    std::cin >> std::setw(sizeof(user_input)) >> user_input;

    // NEW: If there's leftover input after reading into user_input, clear it and warn the user
    if (std::cin.peek() != '\n') {
        std::cin.ignore(10000, '\n'); // clear the rest of the input line
        std::cout << "[!] Warning: You entered too much data. Extra input was ignored." << std::endl;
    }

    std::cout << "You entered: " << user_input << std::endl;
    std::cout << "Account Number = " << account_number << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
