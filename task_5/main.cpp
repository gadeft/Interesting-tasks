#include "../include.h"
#include "../functions.cpp"
#include <vector>

bool palindrome(int number);

int main()
{
    int number;
    std::string input;

    while(true)
    {
        std::cout << "Enter a number: ";

        try
        {
            std::getline(std::cin, input);
            number = check_input(input);
        }
        catch (const char* error)
        {
            std::cerr << error << std::endl;
            continue;
        }
        catch (const std::invalid_argument& ai)
        {
            std::cerr << "Invalid argument: " << ai.what() << std::endl;
            continue;
        }

        std::vector<int> result;

        for (int i = 0; i < number + 1; i++)
            if (palindrome(i) && palindrome(i*i))
                result.push_back(i);

        for (auto it = result.cbegin(); it != result.cend(); it++)
            std::cout << *it << std::endl;
    }
}

bool palindrome(int number)
{
    std::string row = std::to_string(number);
    for (std::string::iterator first_it = row.begin(), second_it = row.end() - 1; first_it < second_it; first_it++, second_it--)
        if (*first_it != *second_it)
            return false;
    return true;
}
