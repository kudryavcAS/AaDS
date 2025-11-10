#include <vector>
#include <fstream>

int main() {
	std::ifstream in("input.txt");
	std::ofstream out("output.txt");

	int n;
	in >> n;
	std::vector<int> array(n);

	for (int i = 0; i < n; i++) {
		in >> array[i];
	}
	in.close();

	bool isHeap = true;
	for (int i = 0; i <= (n - 2) / 2; i++) {
		int left = 2 * i + 1;
		int right = 2 * i + 2;

		if (left < n && array[i] > array[left]) {
			isHeap = false;
			break;
		}
		if (right < n && array[i] > array[right]) {
			isHeap = false;
			break;
		}
	}

	out << (isHeap ? "Yes" : "No");
	out.close();

	return 0;
}
