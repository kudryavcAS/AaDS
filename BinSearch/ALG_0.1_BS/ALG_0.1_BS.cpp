#include <iostream>

bool BinSearch(int* arr, int n, int x) {
	int q = 0, k;

	while (q < n) {
		k = (q + n) / 2;
		if (x == arr[k]) return 1;

		else if (x < arr[k]) n = k;

		else q = k + 1;
	}
	return 0;
}

int LowerBound(int* arr, int n, int x) {
	int q = 0, k;

	while (q < n) {
		k = (q + n) / 2;
		if (x <= arr[k]) n = k;

		else q = k + 1;
	}
	return q;
}

int UpperBound(int* arr, int n, int x) {
	int q = 0, k;

	while (q < n) {
		k = (q + n) / 2;
		if (x < arr[k]) n = k;

		else q = k + 1;
	}
	return q;
}


int main() {
	std::iostream::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	int n, value, k;
	std::cin >> n;
	int* arr = new int[n];
	
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}

	std::cin >> k;
	for (int j = 0; j < k; j++) {
		std::cin >> value;
		std::cout << BinSearch(arr, n, value) << " ";
		std::cout << LowerBound(arr, n, value) << " ";
		std::cout << UpperBound(arr, n, value) << " " << "\n";

	}
	delete[] arr;
}