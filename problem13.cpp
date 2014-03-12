#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

const int maxNumberValue = std::numeric_limits<int>::max() - 1;
const int maxNumberDigits = std::numeric_limits<int>::digits10 - 1;

template<class From, class To>
To convert(From number)
{
  std::stringstream str;
  str << number;
  To value;
  str >> value;
  return value;
}

std::vector<int> split(const std::string& number)
{
  std::vector<int> splittedBigInteger;
  int begin = number.size() - maxNumberDigits;
  while(begin > 0)
  {
    splittedBigInteger.push_back(convert<std::string,int>(number.substr(begin, maxNumberDigits)));
    begin -= maxNumberDigits;
  }
  splittedBigInteger.push_back(convert<std::string,int>(number.substr(0, begin + maxNumberDigits)));

  return splittedBigInteger;
}

std::vector<int> sum(std::vector<int> first, std::vector<int> second)
{
  std::vector<int> result;
  std::size_t size = std::min(first.size(), second.size());
  for(int i = 0; i < size; ++i)
  {
    int partialResult = first.at(i) + second.at(i);
    
    std::string partialResultStr = convert<int,std::string>(partialResult);
    const bool carryNumber = partialResultStr.size() > maxNumberDigits;
    if(carryNumber)
    {
      partialResultStr = partialResultStr.substr(1, partialResultStr.size());
      partialResult = convert<std::string, int>(partialResultStr);
    }

    result.push_back(partialResult);

    if(carryNumber)
      first.at(i+1) = first.at(i+1) + 1;
  }

  return result;
}

int main()
{
  std::ifstream numberFile;
  numberFile.open("numbers.txt");
  std::vector<std::string> numbers;
  std::copy(std::istream_iterator<std::string>(numberFile), 
            std::istream_iterator<std::string>(),
            std::back_insert_iterator<std::vector<std::string>>(numbers));
  std::vector<std::vector<int>> bigint;
  std::transform(begin(numbers), end(numbers), begin(bigint), std::bind(&split,std::placeholders::_1));
  std::string result = std::accumulate(begin(bigint), end(bigint), "0", std::bind(&sum,std::placeholders::_1, std::placeholders::_2));

  // auto firstNumber = split(first);
  // std::copy(begin(firstNumber), end(firstNumber), std::ostream_iterator<int>(std::cout, "\n"));
  // std::cout << std::endl;
  // auto secondNumber = split(second);
  // std::copy(begin(secondNumber), end(secondNumber), std::ostream_iterator<int>(std::cout, "\n"));

  // std::cout << std::endl;
  // std::cout << first << "\n";
  // std::cout << second << "\n";
  // auto result = sum(firstNumber, secondNumber);
  // std::copy(result.rbegin(), result.rend(), std::ostream_iterator<int>(std::cout));
  // std::cout << std::endl;

  return 0;
}
