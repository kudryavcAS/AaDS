#include <iostream>
#include <vector>
#include <fstream>

int h(long long x, int i, int m, int c) {
	return ((x % m) + c * i) % m;
}

int main() {
	std::ifstream in("input.txt");
	std::ofstream out("output.txt");

	int m, c, n;
	in >> m >> c >> n;

	std::vector<long long> table(m, -1);

	for (int k = 0; k < n; k++) {
		long long x;
		in >> x;

		bool inserted = false;
		for (int i = 0; i < m && !inserted; i++) {
			int pos = h(x, i, m, c);
			if (table[pos] == x) {
				inserted = true;
			}
			else if (table[pos] == -1) {
				table[pos] = x;
				inserted = true;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		out << table[i];
		if (i < m - 1) out << " ";
	}

	in.close();
	out.close();
	return 0;
}
