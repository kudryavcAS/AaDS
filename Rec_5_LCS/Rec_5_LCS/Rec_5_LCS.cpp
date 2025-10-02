#include <iostream>
#include <vector>
#include <algorithm>

int main() {

	std::iostream::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> A(n + 1), B(n + 1);

	for (int i = 0; i < n; i++) {
		std::cin >> A[i];
	}
	for (int i = 0; i < n; i++) {
		std::cin >> B[i];
	}

	std::vector<std::vector<int>> lcs(n + 1, std::vector<int>(n + 1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (A[i - 1] == B[j - 1]) {
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}
			else {
				lcs[i][j] = std::max(lcs[i - 1][j], lcs[i][j - 1]);
			}
		}
	}

	int k = lcs[n][n];
	std::vector<short> indexesA, indexesB;

	int i = n, j = n;
	while (i > 0 && j > 0) {
		if (A[i - 1] == B[j - 1]) {
			indexesA.push_back(i - 1);
			indexesB.push_back(j - 1);
			i--;
			j--;
		}
		else if (lcs[i - 1][j] > lcs[i][j - 1]) {
			i--;
		}
		else {
			j--;
		}
	}

	reverse(indexesA.begin(), indexesA.end());
	reverse(indexesB.begin(), indexesB.end());

	std::cout << k << "\n";
	for (short idx : indexesA) {
		std::cout << idx << " ";
	}
	std::cout << "\n";
	for (short idx : indexesB) {
		std::cout << idx << " ";
	}

	return 0;

}