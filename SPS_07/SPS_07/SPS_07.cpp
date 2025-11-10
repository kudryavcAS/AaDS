#include <vector>
#include <fstream>

class DSU {
private:
	std::vector<int> parent;
	int size;
	int components;

public:
	DSU(int _size) :size(_size), components(_size) {
		parent.resize(size, -1);
	}

	int FindSet(int x) {
		return parent[x] < 0 ? x : parent[x] = FindSet(parent[x]);
	}


	bool Union(int x, int y) {
		x = FindSet(x);
		y = FindSet(y);

		if (x == y) {
			return false;
		}

		if (parent[x] > parent[y]) {
			std::swap(x, y);
		}
		parent[x] += parent[y];
		parent[y] = x;

		components--;
		return true;
	}

	int GetComponents() {
		return components;
	}
};

int main() {
	std::ifstream in("input.txt");
	std::ofstream out("output.txt");

	int n, m, q;
	in >> n >> m >> q;

	std::vector<std::pair<int, int>> edges(m);
	for (int i = 0; i < m; i++) {
		int u, v;
		in >> u >> v;
		edges[i].first = u - 1;
		edges[i].second = v - 1;
	}

	std::vector<int> earthquakes(q);
	std::vector<bool> destroyed(m, false);

	for (int i = 0; i < q; i++) {
		in >> earthquakes[i];
		earthquakes[i]--;
		destroyed[earthquakes[i]] = true;
	}

	DSU dsu(n);

	for (int i = 0; i < m; i++) {
		if (!destroyed[i]) {
			dsu.Union(edges[i].first, edges[i].second);
		}
	}

	std::vector<char> result(q);

	for (int i = q - 1; i >= 0; i--) {
		result[i] = (dsu.GetComponents() == 1) ? '1' : '0';

		int index = earthquakes[i];
		dsu.Union(edges[index].first, edges[index].second);
	}

	out.write(result.data(), q);

	in.close();
	out.close();

	return 0;
}
