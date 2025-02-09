#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "../functions.cpp"

std::string name_of_number(int number);

int main()
{
    int number;
    std::vector<int> array;
    std::string input;

    for (int i = 1000, diff = 100; i >= 0; i -= diff)
    {
        array.push_back(i);
        if (i == 100) 
            diff = 10;
        else if (i == 20) 
            diff = 1;
    }

    while (true)
    {
        std::cout << "Enter a number: ";
        std::string result;
        
        try
        {
            std::getline(std::cin, input);
            number = check_input(input);

            if (number > 1000)
                throw "Please enter a number, which will be less or equal a thousand";

            for (auto it = array.cbegin(); it != array.cend(); it++)
            {
                if (number - *it < 0)
                    continue;
                else if (number - *it == 0)
                {
                    result += name_of_number(*it);
                    result += " ";
                    break;
                }
                else
                {
                    result += name_of_number(*it);
                    result += " ";
                    number -= *it;
                }
            }

            std::cout << result << std::endl;
        }
        catch (const char* error)
        {
            std::cerr << error << std::endl;
            continue;
        }
        catch (const std::invalid_argument& ia)
        {
            std::cerr << "Unexpected value" << std::endl;
            continue;
        }

    }
}

std::string name_of_number(int number)
{
    std::string row = std::to_string(number);
    std::ifstream names("names.txt");
    std::string input;

    while (input != "end")
    {
        names >> input;

        if (input == row)
        {
            names >> input;
            return input;
        }
    }
    throw "Something went wrong while reading the file";
}
