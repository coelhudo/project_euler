#include <iostream>

int main()
{
    int limit = 1000;
    int sum = 0;
    while(--limit)
        if(!(limit % 3) || !(limit % 5))
            sum += limit;

    std::cout << sum << std::endl;

    return 0;
}
