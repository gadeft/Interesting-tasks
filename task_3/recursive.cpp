#include <iostream>
#include <string>

int* eratosphen(int p, int* array, int size);
void output(int* array, int size);
int check_input(std::string input);

int main()
{
    int number;
    std::string input;

    while (true)
    {
        std::cout << "Enter a number: ";
        std::getline(std::cin, input);

        number = check_input(input);

        if (number < 2)
            continue;

        int array[number - 1];
        
        for (int i = 0; i < number - 1; i++)
            array[i] = i + 2;

        output(eratosphen(1, array, number - 1), number - 1);
    }
}


int* eratosphen(int p, int* array, int size)
{
    for (int i = p - 1; i < size; i++)
    {
        if (array[i]*array[i] >= size + 1)
            return array;
        else if (!array[i])
            continue;
        else
        {
            p = array[i];
            break;
        }
    }

    for (int i = p - 1; i < size; i++)
        if (array[i] % p == 0)
            array[i] = 0;

    return eratosphen(p, array, size);
}

void output(int* array, int size)
{
    for (int i = 0; i < size; i++)
        if (array[i]) std::cout << array[i] << std::endl;
}

int check_input(std::string input)
{
    for (std::string::iterator it = input.begin(); it != input.end(); it++)
        if (!std::isdigit(*it))
        {
            std::cout << "Unexpected value" << std::endl;
            return -1;
        }
    return std::stoi(input);
}
