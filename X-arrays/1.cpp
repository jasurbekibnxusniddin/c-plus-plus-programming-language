#include <iostream>

int main() {

    int l, sum = 0;

    std::cout << "l = ";
    std::cin >> l;

    int numbers[l];

    for (int i = 0; i < l; i++) {
        std::cout << i <<" element = ";
        std::cin >> numbers[i];
    }

    sum = 0;
    for (int i = 0; i < l; i++) {
       sum += numbers[i];
    }

    std::cout << "sum = " << sum << std::endl;
}