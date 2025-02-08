#include <iostream>
#include <string>
#include "eratosphen.cpp"
#include "../functions.cpp"
#include <stdexcept>

void output(int* array, int size);

int main()
{
    int number;
    std::string input;

    while (true)
    {
        std::cout << "Enter a number: ";

        try
        {
            std::getline(std::cin, input);
            number = check_input(input);

            output(eratosphen(number), number - 1);
        }
        catch (const char* error)
        {
            std::cerr << error << std::endl;
            continue;
        }
        catch (const std::invalid_argument& ia)
        {
            std::cerr << "Invalid argument: " << ia.what() << std::endl;
            continue;
        }

    }
}

void output(int* array, int size)
{
    for (int i = 0; i < size; i++)
        if (array[i]) std::cout << array[i] << std::endl;
}
