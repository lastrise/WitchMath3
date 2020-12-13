#include <iostream>
#include "iomanip"
#include "vector"
#include "algorithm"


double algorithmKahan(const std::vector<double>& numbers)
{
  double resultSum = numbers[0];
  double correction = 0;
  double correctedNextNumber;
  double sumAfterAddNextNumber;

  for (int i = 1; i < numbers.size(); i++) {
    correctedNextNumber = numbers[i] - correction;
    sumAfterAddNextNumber = resultSum + correctedNextNumber;
    correction = (sumAfterAddNextNumber - resultSum) - correctedNextNumber;
    resultSum = sumAfterAddNextNumber;
  }
  return resultSum;
}


int main() {
    auto array = std::vector<double>();

    array.push_back(1.28349124891233111);
    array.push_back(1.44912094012094022);
    array.push_back(1.94102941029492334);
    array.push_back(1.14923012093102948);
    array.push_back(1.65903492034906051);
    array.push_back(1.10940192941024929);

    double correctly = algorithmKahan(array);

    do {
        double sum = algorithmKahan(array);
        std::cout << std::setprecision(17) << sum << std::endl;
        assert(sum == correctly);
    } while (std::next_permutation(array.begin(), array.end()));

    return 0;
}
