#include <iostream>
#include <cmath>
//http://en.wikipedia.org/wiki/Formulas_for_generating_Pythagorean_triples

int main()
{
    for(int a = 0; a < 500; ++a)
        for(int b = 0; b < 500; ++b)
        {
            int candidate = a*a + b*b;
            double square_root = sqrt(candidate);
            double fract, intpart;
            fract = modf(square_root, &intpart);
            if(!(fract > 0.0))
                if(a + b + square_root == 1000){
                    std::cout << a << ", " << b << ", " << square_root << std::endl;
                    std::cout << (a * b * static_cast<int>(square_root)) << std::endl;
                }
        }
    return 0;
}
