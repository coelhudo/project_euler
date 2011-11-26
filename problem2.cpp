#include <iostream>

int fib(int max){
    if(max == 1 || max == 0)
        return 1;
    return fib(max-1)+fib(max-2);
}

int main()
{
    int limit = 1000000;
    int first = 1;
    int second = 2;
    int sum = 2;
    while(limit--)
    {
        int tmp = second;
        second = first + second;
        first = tmp;
        if(!(second %2)){
            sum += second;
            if(second > 4000000)
            {
                sum -= second;
                break;
            }
        }
    }

    std::cout << sum << std::endl;

    return 0;
}
