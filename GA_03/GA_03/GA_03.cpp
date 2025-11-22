#include <fstream>
#include <vector>

struct Vertex {
	int vertex;
	Vertex* next = nullptr;
};

int main() {
	std::ifstream in("input.txt");
	std::ofstream out("output.txt");

	int n, m;
	in >> n >> m;

	std::vector<Vertex*> adj(n + 1, nullptr);

	for (int i = 0; i < m; i++) {
		int u, v;
		in >> u >> v;

		Vertex* newVertex = new Vertex{ v, adj[u] };
		adj[u] = newVertex;

		newVertex = new Vertex{ u, adj[v] };
		adj[v] = newVertex;
	}

	for (int i = 1; i <= n; i++) {
		int count = 0;
		Vertex* current = adj[i];
		while (current != nullptr) {
			count++;
			current = current->next;
		}

		out << count;

		current = adj[i];
		while (current != nullptr) {
			out << " " << current->vertex;
			current = current->next;
		}
		out << "\n";
	}

	for (int i = 1; i <= n; i++) {
		Vertex* current = adj[i];
		while (current != nullptr) {
			Vertex* temp = current;
			current = current->next;
			delete temp;
		}
	}

	in.close();
	out.close();
	return 0;
}