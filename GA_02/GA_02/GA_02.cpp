#include <vector>
#include <fstream>

int main() {
	std::ifstream in("input.txt");
	std::ofstream out("output.txt");

	int n;
	in >> n;

	std::vector<int> parents(n + 1, 0);

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		in >> u >> v;
		parents[v] = u;
	}

	for (int i = 1; i <= n; i++) {
		out << parents[i] << " ";
	}

	in.close();
	out.close();

	return 0;
}