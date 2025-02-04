#include <iostream>
#include <string>

void pascals_triangle(int number);
int check_input(std::string input);

int main()
{
    std::string input;
    int number;

    while (true)
    {
        std::cout << "Enter a number: ";
        std::getline(std::cin, input);

        number = check_input(input);

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
