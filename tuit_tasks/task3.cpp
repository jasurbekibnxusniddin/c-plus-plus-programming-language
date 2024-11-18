// talaba: Jasurbek Shamsitdinov
// variant: 29
// masala: 29. Massivning har bir elementini teskari tartibda chiqaradigan funksiya yarating.
// sana: 16.10.2024

#include <iostream>

void PrintArrayElements(int *arr, int lenArr) {

	if (lenArr < 1) {
		return;
	}
	
	std::cout << arr[lenArr-1];

	return PrintArrayElements(arr, lenArr-1);
}

int main() {

	int arr[5] = {2, 3, 4, 5, 6};

	PrintArrayElements(arr, 5);
}