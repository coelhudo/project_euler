#include <iostream>
#include <vector>
#include <limits>

int main()
{
    std::vector<int> primes = {2, 3, 5, 7, 11, 13, 17};

    int currentLargePrime = primes.back();
    while(primes.size() != 10001)
    {
        currentLargePrime += 2;
        bool isPrime = true;
        for(auto i = primes.cbegin(); i < primes.cend(); ++i)
            isPrime &= ((currentLargePrime % *i) != 0);

        if(isPrime)
            primes.push_back(currentLargePrime);
    }

    std::cout << primes.back() << std::endl;

    return 0;
}
