// 29. Massivni ikkiga bo'lib, ikkala qismdagi elementlar yig'indisini solishtiring.

#include <iostream>
using namespace std;

int main() {
  int arr[] = {1, 2, 3, 5, 2, 2, 4, 5, 5, 3, 3};

  int len = sizeof(arr) / sizeof(arr[0]);

  int sum1 = 0, sum2 = 0;

  for (int i = 0; i < len / 2; i++) {
  	sum1 += arr[i];
  }

  for (int i = len / 2; i < len; i++) {
  	sum2 += arr[i];
  }

  std::cout << sum1 << std::endl;
  std::cout << sum2 << std::endl;
}