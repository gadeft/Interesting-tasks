#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>

int power = 2;

int check_input(std::string input);
void createArray(int n);

int main()
{
    int number;
    std::string input;

    while (true)
    {
        std::cout << "Enter a number: ";
        std::getline(std::cin, input);

        number = check_input(input);

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

int check_input(std::string input)
{
    for (std::string::iterator it = input.begin(); it != input.end(); it++)
    {
        if (!std::isdigit(*it))
        {
            std::cout << "Unexpected value" << std::endl;
            return -1;
        }
    }
    return std::stoi(input);
}
