#include <iostream>

int main()
{
    bool evenlyDivisible = true;
    int first = 0;

    do
    {
        ++first;
        evenlyDivisible = true;
        for (int i = 1; i < 21 && evenlyDivisible; ++i){
            evenlyDivisible &= !(first % i);
        }
    }while(!evenlyDivisible);

    std::cout << first << std::endl;

    return 0;
}
