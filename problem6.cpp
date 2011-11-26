#include <iostream>

int sumOfSquares(int number)
{
    int result = 0;
    do
    {
        result += number*number;
    }while(--number);
    return result;
}

int squareOfTheSums(int number)
{
    int result = 0;
    do
    {
        result += number;
    }while(--number);
    return result*result;
}

int main()
{
    std::cout << (squareOfTheSums(100) - sumOfSquares(100)) << std::endl;

    return 0;
}
