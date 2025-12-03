#include <fstream>
#include <vector>
#include <utility> 

class MinHeap {
private:
	std::vector<std::pair<long long, int>> heap;

	void siftUp(int i) {
		while (i > 0) {
			int parent = (i - 1) / 2;
			if (heap[i].first < heap[parent].first) {
				std::swap(heap[i], heap[parent]);
				i = parent;
			}
			else {
				break;
			}
		}
	}

	void siftDown(int i) {
		int size = heap.size();

		while (true) {
			int left = 2 * i + 1;
			int right = 2 * i + 2;
			int smallest = i;

			if (left < size && heap[left].first < heap[smallest].first) {
				smallest = left;
			}

			if (right < size && heap[right].first < heap[smallest].first) {
				smallest = right;
			}

			if (smallest != i) {
				std::swap(heap[i], heap[smallest]);
				i = smallest;
			}
			else {
				break;
			}
		}
	}

public:
	void insert(long long dist, int u) {
		heap.push_back({ dist, u });
		siftUp(heap.size() - 1);
	}

	std::pair<long long, int> extractMin() {
		std::pair<long long, int> minElem = heap[0];

		heap[0] = heap.back();
		heap.pop_back();

		if (!heap.empty()) {
			siftDown(0);
		}

		return minElem;
	}

	bool empty() const {
		return heap.empty();
	}
};

int main() {
	std::ifstream in("input.txt");
	std::ofstream out("output.txt");

	int n, m;
	in >> n >> m;

	std::vector<std::vector<std::pair<int, int>>> adj(n + 1);

	for (int i = 0; i < m; ++i) {
		int u, v, w;
		in >> u >> v >> w;
		adj[u].push_back({ v, w });
		adj[v].push_back({ u, w });
	}

	const long long INF = LLONG_MAX;
	std::vector<long long> dist(n + 1, INF);

	dist[1] = 0;

	MinHeap pq;
	pq.insert(0, 1);

	while (!pq.empty()) {
		std::pair<long long, int> top = pq.extractMin();
		long long d = top.first;
		int u = top.second;

		if (d > dist[u]) {
			continue;
		}

		for (const auto& edge : adj[u]) {
			int v = edge.first;
			int len = edge.second;

			if (dist[u] + len < dist[v]) {
				dist[v] = dist[u] + len;
				pq.insert(dist[v], v);
			}
		}
	}

	out << dist[n];

	in.close();
	out.close();

	return 0;
}
