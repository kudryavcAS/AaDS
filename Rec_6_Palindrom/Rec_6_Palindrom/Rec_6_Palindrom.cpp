#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main() {

	std::ifstream in("input.txt");
	std::ofstream out("output.txt");

	std::string str;
	in >> str;
	int n = str.length();

	std::vector<std::vector<int>> pal(n, std::vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		pal[i][i] = 1;
	}

	for (int i = 0; i < n - 1; i++) {

		if (str[i] == str[i + 1]) {
			pal[i][i + 1] = 2;
		}
		else {
			pal[i][i + 1] = 1;
		}
	}

	int j;
	for (int len = 3; len <= n; len++) {
		for (int i = 0; i <= n - len; i++) {

			j = i + len - 1;
			if (str[i] == str[j]) {
				pal[i][j] = pal[i + 1][j - 1] + 2;
			}
			else {
				pal[i][j] = std::max(pal[i + 1][j], pal[i][j - 1]);
			}
		}
	}

	std::string left_part;
	int i = 0;
	j = n - 1;
	while (i <= j) {
		if (str[i] == str[j]) {
			left_part += str[i];
			i++;
			j--;
		}
		else {
			if (pal[i + 1][j] > pal[i][j - 1]) {
				i++;
			}
			else {
				j--;
			}
		}
		std::string left, right;
		int i = 0, j = n - 1;
		while (i <= j) {
			if (str[i] == str[j]) {
				left += str[i];
				if (i != j) {
					right = str[i] + right;
				}
				i++;
				j--;
			}
			else {
				if (pal[i + 1][j] > pal[i][j - 1]) {
					i++;
				}
				else {
					j--;
				}
			}
		}

		out << pal[0][n - 1] << "\n" << left+right;

		return 0;
	}
}