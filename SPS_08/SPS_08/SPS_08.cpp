#include <iostream>
#include <vector>
#include <string>

class FenwickTree {
private:
	std::vector<long long> tree;
	int size;

public:
	FenwickTree(int _size) : size(_size) {
		tree.resize(size + 1, 0);
	}

	void update(int pos, int x) {
		for (int i = pos + 1; i <= size; i += i & -i) {
			tree[i] += x;
		}
	}

	long long getSum(int pos) {
		long long sum = 0;
		for (int i = pos + 1; i > 0; i -= i & -i) {
			sum += tree[i];
		}
		return sum;
	}

	long long range_sum(int l, int r) {
		return getSum(r - 1) - getSum(l - 1);
	}
};

int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int n;
	std::cin >> n;

	std::vector<long long> arr(n);
	FenwickTree fenw(n);

	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
		fenw.update(i, arr[i]);
	}

	int q;
	std::cin >> q;

	while (q--) {
		std::string type;
		std::cin >> type;

		if (type == "Add") {
			int i;
			long long x;
			std::cin >> i >> x;
			fenw.update(i, x);
		}
		else if (type == "FindSum") {
			int l, r;
			std::cin >> l >> r;
			std::cout << fenw.range_sum(l, r) << '\n';
		}
	}

	return 0;
}
