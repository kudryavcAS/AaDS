#include <algorithm>
#include <fstream>
#include <vector>

int main()
{
	std::ifstream in("input.txt");
	std::ofstream out("output.txt");

	int s;
	in >> s;

	std::vector<int> n(s), m(s);
	for (int i = 0; i < s; i++) {
		in >> n[i] >> m[i];
	}

	std::vector<std::vector<int>> optiMul(s, std::vector<int>(s, 0));

	for (int i = 0; i < s - 1; i++) {
		optiMul[i][i + 1] = n[i] * m[i] * m[i + 1];
	}

	for (int len = 2; len <= s; len++) {
		for (int i = 0; i <= s - len; i++) {
			int j = i + len - 1;
			optiMul[i][j] = INT_MAX;

			for (int k = i; k < j; k++) {
				int cost = optiMul[i][k] + optiMul[k + 1][j] + n[i] * m[k] * m[j];
				if (cost < optiMul[i][j]) {
					optiMul[i][j] = cost;
				}
			}
		}
	}

	out << optiMul[0][s - 1];

	in.close();
	out.close();
	return 0;
}