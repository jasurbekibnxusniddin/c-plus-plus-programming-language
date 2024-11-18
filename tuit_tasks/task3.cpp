//29. Massivning har bir elementini teskari tartibda chiqaradigan funksiya yarating.
#include <iostream>

void PrintArrayElements(int *arr, int lenArr) {
	lenArr--;

	if (lenArr < 0) {
		return;
	}
	
	std::cout << arr[lenArr];

	return PrintArrayElements(arr, lenArr);
}

int main() {

	int arr[5] = {2, 3, 4, 5, 6};

	PrintArrayElements(arr, 5);
}