#include <iostream>

void output(int* array, int size);

namespace my_lib
{
    struct vector
    {
        int size, capacity;
        int* data;

        vector() : size(0), capacity(8)
        {
            data = new int[capacity];
        }
        vector(int size_) : size(size_), capacity(size_)
        {
            data = new int[capacity];
        }
        vector(int size_, int value_) : size(size_), capacity(size_)
        {
            data = new int[capacity];
            for (int i = 0; i < capacity; i++)
                data[i] = value_;
        }
        vector(const vector& v) : size(v.size), capacity(v.capacity)
        {
            data = new int[capacity];
            for(int i = 0; i < size; i++)
                data[i] = v.data[i];
        }

        int& operator[](int index_)
        {
            return data[index_];
        }
        int& at(int index_)
        {
            if(index_ < 0 || index_ >= size)
                throw "Out of range";
            else
                return data[index_];
        }

        int pop_back()
        {
            if(size <= 0)
                throw "Already empty";
            else
                return data[--size];
        }

        void push_back(int value_)
        {
            std::cout << "In push_back. The size: " << size << ", the capacity: " << capacity << ", the value: " << value_ << std::endl;
            if(size == capacity)
                capacity *= 2;

            size++;
            data[size - 1] = value_;
            std::cout << "\tIn push_back. The size: " << size << ", the capacity: " << capacity << ", the value: " << value_ << ", the init_value: " << data[size - 1] << "\n\n";
        }

        void insert(int index_, int value_)
        {
            if ((index_ < 0) || (index_ >= size))
            {
                throw "Out of range";
                return;
            }

            if(size == capacity)
                capacity *= 2;

            for(int i = size; i > index_; i--)
                data[i] = data[i - 1];

            data[index_] = value_;

            size++;
        }

        ~vector()
        {
            delete[] data;
        }
    };
}

void output(my_lib::vector array);
void output(int* array, int size);


int main()
{
    try
    {
        my_lib::vector v;

        for (int i = 0; i < 100; i++)
            v.push_back(i);

        std::cout << "A function" << std::endl;
        output(v);
    }
    catch(const char* error)
    {
        std::cerr << error << std::endl;
    }
}

void output(my_lib::vector array)
{
    std::cout << "In output" << std::endl;
    for(int i = 0; i < array.size; i++)
        std::cout << i << ": " << array[i] << std::endl;
}

void output(int* array, int size)
{
    std::cout << "In output" << std::endl;
    for(int i = 0; i < size; i++)
        std::cout << i << ": " << array[i] << std::endl;
}
