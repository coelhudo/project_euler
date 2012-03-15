#include <iostream>
#include <vector>

int main()
{
    int max = 2000000;

    std::vector<int> primes = {2, 3, 5, 7, 11, 13, 17};

    int currentLargePrime = primes.back();
    while(primes.back() < 2000000)
    {
        currentLargePrime += 2;
        bool isPrime = true;
        for(auto i = primes.cbegin(); i < primes.cend(); ++i)
            isPrime &= ((currentLargePrime % *i) != 0);
        if(isPrime)
            primes.push_back(currentLargePrime);
    }

    //std::cout << primes.back() << std::endl;

    int sum;
    for(auto i = primes.cbegin(); i < primes.cend(); ++i)
        sum += *i;

    std::cout << sum << std::endl;

    return 0;
}
