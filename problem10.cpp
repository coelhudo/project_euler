#include <iostream>
#include <vector>

int main()
{
    std::vector<int> candidates;
    const int max = 2000000;
    for(int i = 2; i < max; ++i)
        //if(!(i % 2 && i % 3 && i % 5 && i % 7))
        if(!(i % 2 == 0) && !(i % 3 == 0) && !(i % 5 == 0) && !(i % 7 == 0)
           && !(i % 11 == 0) && !(i % 13 == 0) && !(i % 17 == 0) && !(i % 19 == 0))
            candidates.push_back(i);

    std::cout << candidates.size() << std::endl;

    std::vector<int> primes = {2, 3, 5, 7, 11, 13, 17};

    auto candidate = candidates.begin();
    while(candidate != candidates.end())
    {
        bool isPrime = true;
        for(auto i = primes.cbegin(); i < primes.cend(); ++i)
            isPrime &= ((*candidate % *i) != 0);
        if(isPrime)
        {
            primes.push_back(*candidate);
        }
        candidate++;
    }

    std::cout << primes.size() << std::endl;

    int sum;
    for(auto i = primes.cbegin(); i < primes.cend(); ++i)
        sum += *i;

    std::cout << sum << std::endl;

    return 0;
}
