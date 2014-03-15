#include <iostream>
#include <algorithm>
#include <map>

std::map<unsigned int, unsigned int> lengthCounterPerValue;

void collatz(unsigned int n, unsigned int &count)
{
  auto result = lengthCounterPerValue.find(n);
  if(result != std::end(lengthCounterPerValue))
  {
    count += result->second;
    return;
  }

  ++count;

  if(n == 1)
  {
    return;
  }
  else if(n % 2)
  {
    n = n * 3 + 1;
    collatz(n, count);
  }
  else
  {
    n = n / 2;
    collatz(n, count);
  }
}

int main()
{
  for(unsigned int i = 1; i < 1000000; ++i)
  {
    unsigned int count = 0;
    collatz(i, count);
    lengthCounterPerValue[i] = count;
  }

  typedef std::pair<unsigned int, unsigned int> ValueLengthPair;
  auto result = std::max_element(std::begin(lengthCounterPerValue),
                                 std::end(lengthCounterPerValue),
                                 [](const  ValueLengthPair& lhs, const ValueLengthPair &rhs) -> bool
                                 {
                                   return !(lhs.first > 999999 || rhs.first > 999999) && lhs.second < rhs.second;
                                 });
  std::cout << "Value: " << result->first << ", length: " << result->second << std::endl;

  return 0;
}
