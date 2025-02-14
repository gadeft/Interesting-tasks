#include "../include.h"
#include "../functions.cpp"
#include "../task_3/eratosphen.cpp"
#include <vector>

int main()
{
    int number;
    std::string input;
    int* array;

    while (true)
    {
        std::cout << "Enter a number: ";

        try
        {
            std::getline(std::cin, input);
            number = check_input(input);
            if (number < 2)
                throw "Unexpected value";

            array = eratosphen(number*2);
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

        std::vector<int*> result;

        for (int main_it = number - 2, supp_it = number - 2; main_it < number*2 - 1; main_it++)
        {
            if (!array[main_it])
                continue;
            else if (array[main_it] - array[supp_it] == 2)
            {
                int* pair = new int[2]{array[supp_it], array[main_it]};
                result.push_back(pair);

                supp_it = main_it;
            }
            else supp_it = main_it;
        }

        for (auto it = result.cbegin(); it != result.cend(); it++)
        {
            for (int i = 0; i < 2; i++)
                std::cout << (*it)[i] << ' ';
            std::cout << std::endl;
        }
    }
}
