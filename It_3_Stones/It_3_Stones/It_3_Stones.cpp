#include <iostream>
#include <vector>

class FenwickTree {
private:
	std::vector<int> tree;
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

	int getSum(int pos) {
		int sum = 0;
		for (int i = pos + 1; i > 0; i -= i & -i) {
			sum += tree[i];
		}
		return sum;
	}

	int range_sum(int l, int r) {
		return getSum(r - 1) - getSum(l - 1);
	}

	int findStonePos(int k) {
		int l = 0, r = size - 1;
		while (l <= r) {
			int m = (l + r) / 2;
			if (getSum(m) >= k) {
				r = m - 1;
			}
			else {
				l = m + 1;
			}
		}
		return l;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	int n;
	std::cin >> n;

	FenwickTree stones(n);
	
	for (int i = 0; i < n; i++) {
		stones.update(i, 1);
	}

	std::vector<int> result;
	for (int i = 0; i < n; i++) {
		int q;
		std::cin >> q;

		int pos = stones.findStonePos(q);
		int stoneSize = pos + 1;
		result.push_back(stoneSize);

		stones.update(pos, -1);
	}

	for (int size : result) {
		std::cout << size << "\n";
	}

	return 0;
}
