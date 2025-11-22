#include <iostream>
#include <fstream>
#include <vector>

int main() {
	std::ifstream in("input.txt");
	std::ofstream out("output.txt");

	int n;
	in >> n;

	std::vector<int> parents(n + 1, 0);
	std::vector<std::vector<int>> matrix(n + 1, std::vector<int>(n + 1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			in >> matrix[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (matrix[i][j] == 1) {
				parents[j] = i;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		out << parents[i] << " ";
	}

	in.close();
	out.close();
	return 0;
}