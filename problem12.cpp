#include <algorithm>
#include <iostream>
#include <set>
#include <boost/lexical_cast.hpp>

int findAllFactors(const unsigned long long& value){
    unsigned long long current_factor = 2;
    unsigned long long current_value = value;
    unsigned long long result = 2;

    for(int candidate = 1;candidate < value; ++candidate)
        if(!(value % candidate))
            result.insert(candidate);
    result.insert(value);

    return result;
}

int main(int argc, char** argv){
    int max = boost::lexical_cast<int>(argv[1]);
    unsigned long long ndigits = 1;
    unsigned long long current = ndigits;
    int factors = 0;
    while(factors < max)
    {
        factors = findAllFactors(current);
        current = current + ++ndigits;
    }

    std::cout << ( ndigits - 1 ) << std::endl;
    std::cout << ( current - ndigits ) << std::endl;

    return 0;
}
