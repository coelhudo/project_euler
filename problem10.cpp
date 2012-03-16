#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> candidates;
    const int max = 10;
    for(int i = 2; i < max; i++)
        if(i % 2)
            candidates.push_back(i);

    std::cout << candidates.size() << std::endl;
    auto next_candidate_it = candidates.begin();
    auto end = candidates.end();

    std::vector<int> primes = {2};

    while(next_candidate_it != end)
    {
        std::cout << "Tamanho dos candidatos: " << candidates.size() << std::endl;
        std::cout << "Proximo candidato: " << *next_candidate_it << std::endl;
        int next_candidate = *next_candidate_it;
        end = remove_if(candidates.begin(), candidates.end(),
                        [next_candidate](int prime){
                            std::cout << "Candidato: " << prime << ", Next: " << next_candidate << ", " << (prime % next_candidate) << std::endl;
                            if(!(prime % next_candidate)){
                                std::cout << "Entrou\n";
                                return true;
                            }else{
                                return false;
                            }
                        });
        candidates.erase(end);
        primes.push_back(next_candidate);
        next_candidate_it = candidates.begin();
        std::for_each(candidates.cbegin(), candidates.cend(), [](int prime){ std::cout << prime << " ";});
        std::cout << std::endl;
    }

    int sum = 0;
    std::for_each(primes.cbegin(), primes.cend(), [](int prime){ std::cout << prime << " ";});
    std::cout << std::endl;
    std::for_each(primes.cbegin(), primes.cend(), [&sum](int prime){ sum += prime;});
    std::cout << sum << std::endl;

    return 0;
}
