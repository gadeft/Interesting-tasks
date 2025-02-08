int* recursive(int p, int* array, int size);

int* eratosphen(int number)
{
    if (number < 2)
        throw "Unexpected value";
    
    int* array = new int[number - 1];

    for (int i = 0; i < number - 1; i++)
        array[i] = i + 2;

    return recursive(1, array, number - 1);
}

int* recursive(int p, int* array, int size)
{
    for (int i = p - 1; i < size; i++)
    {
        if (array[i]*array[i] > size + 1)
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

    return recursive(p, array, size);
}
