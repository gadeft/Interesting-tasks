#include "../include.h"
#include "../functions.cpp"
#include "../task_3/eratosphen.cpp"
#include <vector>

int main()
{
    int number;
    std::string input;
    int* array;

    while(true)
    {
        std::cout << "Enter a number: ";

        try
        {
            std::getline(std::cin, input);
            number = check_input(input);
            array = eratosphen(number);
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
        
        int i = 0;
        while(i < number - 1)
        {
            if (!array[i])
            {
                i++;
                continue;
            }
            else if (number % array[i] == 0)
            {
                result.push_back(array[i]);
                number /= array[i];
            }
            else i++;
        }

        for (auto it = result.cbegin(); it != result.cend(); it++)
            std::cout << *it << std::endl;
    }
}
