#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/function.hpp>
#include <iterator>

bool isPalindrome(const int &i)
{
    bool result = true;
    std::string p = boost::lexical_cast<std::string>(i);
    std::string::iterator it = p.begin();
    std::string::iterator end = p.end();

    bool even = p.size() % 2;

    do{
        result &= (*it == *(--end));
    }while((even ? it++ : ++it) != end);

    return result;
}

void test()
{
    std::cout << isPalindrome(1) << std::endl;
    std::cout << isPalindrome(11) << std::endl;
    std::cout << isPalindrome(111) << std::endl;
    std::cout << isPalindrome(121) << std::endl;
    std::cout << isPalindrome(1221) << std::endl;
    std::cout << isPalindrome(1220) << std::endl;
}

int main()
{
    int large = 0;
    for(int i = 1; i < 999; ++i)
        for(int j = 1; j < 999; ++j)
        {
            int number = i*j;
            if(isPalindrome(number))
            {
                if(number > large)
                    large = number;
            }
        }

    std::cout << large << std::endl;

    return 0;
}
