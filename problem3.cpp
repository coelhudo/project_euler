#include <iostream>
#include <boost/cstdint.hpp>

void findFactor(boost::uint64_t &number)
{
    int i = 1;
    bool findPrime = true;
    while(findPrime)
    {
        if(!(number % ++i))
        {
            std::cout << i << std::endl;
            number = number / i;
            findPrime = false;
        }
    }

}

int main()
{
    boost::uint64_t limit = 600851475143;
    while(limit != 1)
        findFactor(limit);

    std::cout << limit << std::endl;
    return 0;
}
