#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> candidates;
    const int max = 2000000;
    for(int i = 2; i < max; i++)
        if(i % 2)
            candidates.push_back(i);

    auto next_candidate_it = candidates.begin();
    auto end = candidates.end();

    std::vector<int> primes = {2};

    while(next_candidate_it != end)
    {
        int next_candidate = *next_candidate_it;
        end = remove_if(candidates.begin(), candidates.end(),
                        [next_candidate](int prime){ return !(prime % next_candidate);});
        candidates.erase(end, candidates.end());
        primes.push_back(next_candidate);
        next_candidate_it = candidates.begin();
    }

    unsigned long long sum = 0;
    std::for_each(primes.cbegin(), primes.cend(), [&sum](int prime){ sum += prime;});
    std::cout << sum << std::endl;

    return 0;
}
