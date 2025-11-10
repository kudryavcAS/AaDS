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
		if (x < 0 || x >= size) {
			return -1;
		}

		if (parent[x] < 0) {
			return x;
		}

		return parent[x] = FindSet(parent[x]);
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

	int n, q;
	in >> n >> q;

	DSU dsu(n);

	for (int i = 0; i < q; i++) {
		int u, v;
		in >> u >> v;
		u--; v--;

		dsu.Union(u, v);
		out << dsu.GetComponents() << "\n";
	}

	in.close();
	out.close();

	return 0;
}
