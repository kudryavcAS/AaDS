#include <vector>
#include <fstream>

int main() {
	std::ifstream in("huffman.in");
	std::ofstream out("huffman.out");

	int n = 0;
	in >> n;

	std::vector<int> array(n);

	for (int i = 0; i < array.size(); i++) {
		in >> array[i];
	}
	in.close();

	long long result = 0;
	std::vector<long long> sums;
	sums.reserve(n);
	int i, j;
	i = j = 0;

	for (int k = 1; k < n; k++) {
		long long x, y;

		if (j == sums.size() || (i < n && array[i] < sums[j]))
		{
			x = array[i++];
		}
		else {
			x = sums[j++];
		}

		if (j == sums.size() || (i < n && array[i] < sums[j]))
		{
			y = array[i++];
		}
		else {
			y = sums[j++];
		}

		long long sum = x + y;
		result += sum;
		sums.push_back(sum);
	}

	out << result;
	out.close();

	return 0;
}
