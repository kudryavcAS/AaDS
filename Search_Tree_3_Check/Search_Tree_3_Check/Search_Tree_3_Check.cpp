#include <vector>
#include <fstream>
#include <cstdio>

using namespace std;
int main() {

	FILE* in = fopen("bst.in", "r");
	FILE* out = fopen("bst.out", "w");

	int n, key, parent;
	char side;
	fscanf(in, "%d", &n);

	std::vector<int>keys(n + 1);
	std::vector<int>leftBound(n + 1);
	std::vector<int>rightBound(n + 1);

	fscanf(in, "%d", &key);
	keys[1] = key;
	leftBound[1] = INT_MIN;
	rightBound[1] = INT_MAX;


	for (int i = 2; i < n + 1; i++) {
		fscanf(in, "%d %d %c", &key, &parent, &side);

		if (side == 'L') {
			if (key < leftBound[parent] || key >= keys[parent]) {
				fprintf(out, "NO");
				fclose(in);
				fclose(out);
				return 0;
			}
			keys[i] = key;
			leftBound[i] = leftBound[parent];
			rightBound[i] = keys[parent] - 1;
		}
		else {
			if (key < keys[parent] || key > rightBound[parent]) {
				fprintf(out, "NO");
				fclose(in);
				fclose(out);
				return 0;
			}
			keys[i] = key;
			leftBound[i] = keys[parent];
			rightBound[i] = rightBound[parent];
		}

	}

	fprintf(out, "YES");
	fclose(in);
	fclose(out);
}