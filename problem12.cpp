#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <functional>

std::set<int> findAllFactors(const int& value){
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

    return result;
}

int main(){
    std::set<int> factors = {1};
    unsigned long long ndigits = 1;
    unsigned long long current = ndigits;
    while(factors.size() < 100)
    {
        factors = findAllFactors(current);
        current = current + ++ndigits;
    }

    std::for_each(factors.begin(), factors.end(), [](int value){ std::cout << value << ", ";});
    std::cout << std::endl;

    std::cout << ( ndigits - 1 ) << std::endl;
    std::cout << ( current - ndigits ) << std::endl;

    return 0;
}
