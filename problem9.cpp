#include <iostream>
//http://en.wikipedia.org/wiki/Formulas_for_generating_Pythagorean_triples

bool isPythagoreanTriple(const int& a, const int& b, const int& c)
{
    if(!(a < b < c))
        return false;

    return (a*a + b*b == c*c);
}

int main()
{
    int a = 3;
    int b = 4;
    int c = 5;

    if(isPythagoreanTriple(a,b,c))
    {
        std::cout << (a+b+c) << std::endl;
        std::cout << (a*b*c) << std::endl;
    }

    return 0;
}
