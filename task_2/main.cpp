#include "../include.h"
#include "../functions.cpp"

void pascals_triangle(int number);

int main()
{
    std::string input;
    int number;

    while (true)
    {
        std::cout << "Enter a number: ";

        try
        {
            std::getline(std::cin, input);
            number = check_input(input);
            if (number < 1)
                throw "Unexpected value";
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

        pascals_triangle(number);
    }
}

void pascals_triangle(int number)
{
    int array[number][number];

    for (int i = 0; i < number; i++)
    {
        array[i][0] = 1;
        array[i][i] = 1;

        for (int j = 1; j < i; j++)
            array[i][j] = array[i - 1][j] + array[i - 1][j - 1];
    }

    for (int row = 0; row < number; row++)
    {
        for (int col = 0; col < row + 1; col++)
            std::cout << array[row][col] << ' ';

        std::cout << std::endl;
    }
}
