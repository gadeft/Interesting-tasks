#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include "../functions.cpp"
#include <stdexcept>

int power = 2;

void createArray(int n);

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
        }
        catch (const char* error)
        {
            std::cout << error << std::endl;
            continue;
        }
        catch (const std::invalid_argument& ai)
        {
            std::cerr << "Invalid argument: " << ai.what() << std::endl;
            continue;
        }

        createArray(number);
    }
}

void createArray(int n)
{
   for (int a = 2; a < n; a++)
   {
       for (int b = 2; b < n; b++)
       {
           for (int c = std::max(a, b); c <= n; c++)
           {
                if (pow(a, power) + pow(b, power) == pow(c, power))
                {
                    std::cout << "a: " << a << "\t" << "b: " << b << '\t' << "c: " << c << '\t' << std::endl;
                }
           }
       }
   }
}
