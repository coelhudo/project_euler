#include <algorithm>
#include <iostream>
#include <set>
#include <boost/lexical_cast.hpp>

int findAllFactors(const int& value){
    std::set<int> result = {1};
    int current_factor = 2;
    int current_value = value;

    while(current_value != 1){
        if(!(current_value % current_factor))
            result.insert(current_factor);
        while(!(current_value % current_factor))
        {
            result.insert(current_value);
            current_value = current_value/current_factor;
        }
        ++current_factor;
    }

    return result.size();
}

int main(int argc, char **argv){
    int numberOfFactors = boost::lexical_cast<int>(argv[1]);

    unsigned long long ndigits = 1;
    unsigned long long current = ndigits;

    do{
        current = current + ++ndigits;
    }while(findAllFactors(current) < numberOfFactors);

    return 0;
}
