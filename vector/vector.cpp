#include <iostream>

struct vector
{
    int size;
    int capacity;
    int* array;

    vector(int size = 10):capacity(size*2)
    {
        array = new int[capacity];
        this->size = size;
    }

    void set_value(int value, int index)
    {
        try
        {
            if (index >= size || index < 0)
                throw "The index is out of range";
            else
                array[index] = value;
        }
        catch (const char* error)
        {
            std::cout << error << std::endl;
            exit(-1);
        }
    }

    int get_value(int index)
    {
        try
        {
            if (index >= size || index < 0)
                throw "The index is out of range";
            else
                return array[index];
        }
        catch (const char* error)
        {
            std::cout << error << std::endl;
            exit(-1);
        }
    }

    ~vector()
    {
        delete[] array;
    }
};

int main()
{
    vector v(10);
    for (int i = 0; i < 51; i++)
    {
        v.set_value(i, i);
        std::cout << v.get_value(i) << std::endl;
    }
}
