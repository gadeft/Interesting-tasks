#include <iostream>

int* eratosphen(int n, int* array, int size);
void output(int* array, int size);

int main()
{
    int number;

    while (true)
    {
        std::cout << "Enter a number: ";
        std::cin >> number;

        int array[number - 1];
        
        for (int i = 0; i < number - 1; i++)
            array[i] = i + 2;

        output(eratosphen(1, array, number - 1), number - 1);
    }
}


int* eratosphen(int n, int* array, int size)
{
    for (int i = n + 1; i < size; i++)
    {
        if (i*i > size + 1)
            return array;

        else if (!array[i])
            continue;

        else
            n = i;
            break;
    }

    for (int i = 2; i < size; i++) 
        array[n*i - 2] = 0;

    return eratosphen(n, array, size);
}

void output(int* array, int size)
{
    for (int i = 0; i < size; i++)
        if (array[i]) std::cout << array[i] << std::endl;
}
