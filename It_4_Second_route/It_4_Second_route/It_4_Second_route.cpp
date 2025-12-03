#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

struct State {
	long long d;
	int u;
	int k;

	bool operator>(const State& other) const {
		return d > other.d;
	}
};

struct ParentInfo {
	int u;
	int k;
};

int main() {
	std::ifstream in("input.in");
	std::ofstream out("output.out");

	int n, m;
	in >> n >> m;

	std::vector<std::vector<std::pair<int, int>>> adj(n + 1);
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		in >> u >> v >> w;
		adj[u].push_back({ v, w });
	}

	int start, end;
	in >> start >> end;

	const long long INF = LLONG_MAX;
	std::vector<std::vector<long long>> dist(n + 1, std::vector<long long>(2, INF));
	std::vector<std::vector<ParentInfo>> parent(n + 1, std::vector<ParentInfo>(2, { 0, 0 }));

	std::priority_queue<State, std::vector<State>, std::greater<State>> pq;

	dist[start][0] = 0;
	pq.push({ 0, start, 0 });

	while (!pq.empty()) {
		State top = pq.top();
		pq.pop();

		long long d = top.d;
		int u = top.u;
		int k = top.k;

		if (d > dist[u][k]) {
			continue;
		}

		for (const auto& edge : adj[u]) {
			int v = edge.first;
			int w = edge.second;

			long long newDist = d + w;

			if (newDist < dist[v][0]) {
				dist[v][1] = dist[v][0];
				parent[v][1] = parent[v][0];

				if (dist[v][1] != INF) {
					pq.push({ dist[v][1], v, 1 });
				}

				dist[v][0] = newDist;
				parent[v][0] = { u, k };
				pq.push({ dist[v][0], v, 0 });
			}
			else if (newDist < dist[v][1]) {
				dist[v][1] = newDist;
				parent[v][1] = { u, k };
				pq.push({ dist[v][1], v, 1 });
			}
		}
	}

	out << dist[end][1] << "\n";

	std::vector<int> path;
	int current = end;
	int currentK = 1;

	while (current != 0) {
		path.push_back(current);
		ParentInfo p = parent[current][currentK];
		current = p.u;
		currentK = p.k;
	}

	std::reverse(path.begin(), path.end());

	for (size_t i = 0; i < path.size(); ++i) {
		out << path[i] << " ";
	}

	in.close();
	out.close();

	return 0;
}
