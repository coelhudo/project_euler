#include <algorithm>
#include <iostream>
#include <set>
#include <boost/lexical_cast.hpp>

void reallyFind(unsigned long long &result,
                unsigned long long &current_factor,
                unsigned long long &current_value){
    while(!(current_value % current_factor))
    {
        ++result;
        current_value = current_value/current_factor;
    }
}

int findAllFactors(const unsigned long long& value){
    unsigned long long current_factor = 2;
    unsigned long long current_value = value;
    unsigned long long result = 2;

    reallyFind(result, current_factor, current_value);
    ++current_factor;
    while(current_value != 1){
        reallyFind(result, current_factor, current_value);
        current_factor += 2;
    }

    return result;
}

int main(int argc, char **argv){
    int numberOfFactors = boost::lexical_cast<int>(argv[1]);

    unsigned long long ndigits = 1;
    unsigned long long current = ndigits;

    do{
        current = current + ++ndigits;
    }while(findAllFactors(current) < numberOfFactors);

    std::cout << "N: "<< ndigits << " -> "<< current << std::endl;

    return 0;
}
