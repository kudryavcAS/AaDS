#include <fstream>
#include <vector>

int main() {
	std::ifstream in("input.txt");
	std::ofstream out("output.txt");

	int n, m;
	in >> n >> m;

	std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));

	for (int i = 0; i < m; i++) {
		int u, v;
		in >> u >> v;
		matrix[u - 1][v - 1] = 1;
		matrix[v - 1][u - 1] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			out << matrix[i][j];
			if (j < n - 1) {
				out << " ";
			}
		}
		out << "\n";
	}

	in.close();
	out.close();

	return 0;
}
