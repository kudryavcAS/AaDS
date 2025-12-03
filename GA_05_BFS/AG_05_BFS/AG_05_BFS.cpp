#include <fstream>
#include <vector>
#include <queue>

class Graph {
private:
	int n;
	std::vector<std::vector<int>> matrix;
	std::vector<int> labels;
	std::vector<bool> visited;
	int currentLabel = 0;

	void bfsInternal(int startVertex) {
		std::queue<int> q;

		visited[startVertex] = true;
		labels[startVertex] = currentLabel++;
		q.push(startVertex);

		while (!q.empty()) {
			int u = q.front();
			q.pop();

			for (int vertex = 0; vertex < n; ++vertex) {
				if (matrix[u][vertex] == 1 && !visited[vertex]) {
					visited[vertex] = true;
					labels[vertex] = currentLabel++;
					q.push(vertex);
				}
			}
		}
	}

	void dfsInternal(int u) {
		visited[u] = true;
		labels[u] = currentLabel++;

		for (int vertex = 0; vertex < n; ++vertex) {
			if (matrix[u][vertex] == 1 && !visited[vertex]) {
				dfsInternal(vertex);
			}
		}
	}

public:
	Graph(std::istream& is) {
		is >> n;
		matrix.resize(n, std::vector<int>(n));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				is >> matrix[i][j];
			}
		}
	}

	void solveBFS() {
		labels.assign(n, 0);
		visited.assign(n, false);
		currentLabel = 1;

		for (int i = 0; i < n; ++i) {
			if (!visited[i]) {
				bfsInternal(i);
			}
		}
	}

	void solveDFS() {
		labels.assign(n, 0);
		visited.assign(n, false);
		currentLabel = 1;

		for (int i = 0; i < n; ++i) {
			if (!visited[i]) {
				dfsInternal(i);
			}
		}
	}

	void printResult(std::ostream& out) const {
		for (int i = 0; i < n; ++i) {
			out << labels[i] << (i == n - 1 ? "" : " ");
		}
		out << "\n";
	}
};

int main() {
	std::ifstream inputFile("input.txt");
	std::ofstream outputFile("output.txt");

	Graph graph(inputFile);

	graph.solveBFS();
	//graph.solveDFS();

	graph.printResult(outputFile);

	inputFile.close();
	outputFile.close();

	return 0;
}
