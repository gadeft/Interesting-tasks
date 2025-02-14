#include "../include.h"
#include "../functions.cpp"
#include <vector>


int summ(int* array, int size);
int prod(int* array, int size);
void output(std::vector<int*> vector, int size);
int* copy(int* array, int size);
std::vector<int*> magic(std::vector<int*> result, int* array, int number, int index, int value);

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
        catch (const std::invalid_argument& ia)
        {
            std::cerr << "Unexpected value" << std::endl;
            continue;
        }

        std::vector<int*> result;
        int* array = new int[number];
        
        output(magic(result, array, number, 0, 1), number);
    }
}

std::vector<int*> magic(std::vector<int*> result, int* array, int number, int index, int value)
{
    for (int i = value; i <= number; i++)
    {
        array[index] = i;
        if (index < number - 1)
        {
            result = magic(result, array, number, index + 1, array[index]);
        }
        else if(summ(array, number) == prod(array, number))       
        {
            result.push_back(copy(array, number));
        }
    }
    return result;
}

int summ(int* array, int size)
{
    int the_summ = 0;
    for (int i = 0; i < size; i++)
        the_summ += array[i];
    return the_summ;
}

int prod(int* array, int size)
{
    int the_prod = 1;
    for (int i = 0; i < size; i++)
        the_prod *= array[i];
    return the_prod;
}

void output(std::vector<int*> vector, int size)
{
    std::cout << "The result: " << std::endl;
    for (auto it = vector.cbegin(); it != vector.cend(); it++)
    {
        for (int i = 0; i < size; i++)
            std::cout << (*it)[i] << ' ';
        std::cout << std::endl;
    }
}

int* copy(int* array, int size)
{
    int* output = new int[size];
    for (int i = 0; i < size; i++)
        output[i] = array[i];
    return output;
}
