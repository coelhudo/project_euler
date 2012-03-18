#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

std::map<int, int> ndigitsAndFactors;

std::vector<int> findAllFactors(const int& value){

    std::vector<int> result;
    //if(value % 2 && value % 3 && value % 5)
    // return result;

    int candidate = 1;
    //    std::cout << "old candidate: " << candidate << std::endl;
    std::for_each(ndigitsAndFactors.begin(), ndigitsAndFactors.end(),
                  [&candidate, value, &result](std::pair<int,int> ndigitsAndFactorPair) {
                      if(!(value % ndigitsAndFactorPair.first)){
                          std::cout << "Value: " << value << std::endl;
                          std::cout << "First: " << ndigitsAndFactorPair.first << std::endl;
                          std::cout << "Second: " << ndigitsAndFactorPair.second << std::endl;
                      }
                  });
 
    std::cout << "new candidate: " << candidate << std::endl;
    for(; candidate < value; ++candidate)
        if(!(value % candidate))
            result.push_back(candidate);
    result.push_back(value);

    return result;
}

int main(){
    std::vector<int> factors;
    unsigned long long ndigits = 1;
    unsigned long long current = ndigits;
    while(factors.size() < 5)
    {
        factors = findAllFactors(current);
        ndigitsAndFactors[current] = factors.size();
        std::cout << std::endl;
        current = current + ++ndigits;
    }

    std::for_each(ndigitsAndFactors.begin(), ndigitsAndFactors.end(), [](std::pair<int,int> ndigitsAndFactorPair){
            std::cout << "NDigit: " << ndigitsAndFactorPair.first <<
                ", Factors: " << ndigitsAndFactorPair.second << std::endl;
        });


    std::cout << ( ndigits - 1 ) << std::endl;
    std::cout << ( current - ndigits ) << std::endl;

    return 0;
}
