#include <iostream>

bool isPalindrome(int arr[], int start, int end) {
    // Start va end indekslari orasidagi segmentni palindromligini tekshirish
    while (start < end) {
        if (arr[start] != arr[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main() {
    // Massivni aniqlash
    const int n = 9; // Massiv o'lchami
    int arr[n] = {1, 2, 3, 2, 1, 4, 4, 4, 1}; // Massiv qiymatlari

    std::cout << "Massiv: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Massivdagi palindrom segmentlar:\n";

    // Palindrom segmentlarni topish
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (isPalindrome(arr, i, j)) {
                std::cout << "Indekslar [" << i << ", " << j << "] -> { ";
                for (int k = i; k <= j; ++k) {
                    std::cout << arr[k] << " ";
                }
                std::cout << "}\n";
            }
        }
    }

    return 0;
}
