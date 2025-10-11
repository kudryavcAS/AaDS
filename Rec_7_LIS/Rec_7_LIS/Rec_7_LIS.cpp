#include <fstream>
#include <vector>

int LowerBound(const std::vector<int>& vec, int x) {
	int q = 0;
	int n = vec.size();

	while (q < n) {
		int k = (q + n) / 2;
		if (x <= vec[k]) {
			n = k;
		}
		else {
			q = k + 1;
		}
	}
	return q;
}

int main() {
	
	std::ifstream in("input.txt");
	std::ofstream out("output.txt");

	int n, len;
	in >> n;
	
	std::vector<int> seq(n), last;
	for (int i = 0; i < n; i++) {
		in >> seq[i];
	}

	for (int x : seq) {
		int pos = LowerBound(last, x);
		
		if (pos == last.size()) {
			last.push_back(x);
		}
		else {
			last[pos] = x;
		}
	}

	out << last.size();

}