#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

template <typename T>
class SearchBinTree {
private:
	struct Vertex {
		T value;
		Vertex* left = nullptr;
		Vertex* right = nullptr;

		Vertex(T x) {
			value = x;
		}

		void printDirectLeftBypass(std::ofstream& out) {
			out << this->value << "\n";

			if (this->left != nullptr) {
				this->left->printDirectLeftBypass(out);
			}
			if (this->right != nullptr) {
				this->right->printDirectLeftBypass(out);
			}
		}
	};

	Vertex* root = nullptr;
	int count = 0;

	void clear(Vertex* current) {

		if (current != nullptr) {
			clear(current->left);
			clear(current->right);
			delete current;
		}
	}

	Vertex* findMin(Vertex* vertex) {
		if (vertex == nullptr) return nullptr;
		while (vertex->left != nullptr) {
			vertex = vertex->left;
		}
		return vertex;
	}
	Vertex* findVertex(Vertex* vertex, T key) {
		if (vertex == nullptr || vertex->value == key) {
			return vertex;
		}
		if (key < vertex->value) {
			return findVertex(vertex->left, key);
		}
		else {
			return findVertex(vertex->right, key);
		}
	}
public:
	SearchBinTree(int count) {
		this->count = count;
	}
	SearchBinTree() {}
	~SearchBinTree() {
		clear(root);
	}

	void setRoot(Vertex* root) {
		this->root = root;
	}
	Vertex* getRoot() {
		return root;
	}

	void SetVertex(T x) {
		if (root == nullptr) {
			root = new Vertex(x);
			count++;
			return;
		}
		Vertex* current = root;
		while (current != nullptr) {
			if (x > current->value) {
				if (current->right != nullptr)
				{
					current = current->right;
				}
				else {
					current->right = new Vertex(x);
					count++;
					break;
				}
			}
			else if (x < current->value) {
				if (current->left != nullptr)
				{
					current = current->left;
				}
				else {
					current->left = new Vertex(x);
					count++;
					break;
				}
			}
			else {
				break;
			}
		}
	}

	void printDirectLeftBypass(std::ofstream& out) {
		if (root != nullptr) {
			root->printDirectLeftBypass(out);
		}
	}

	Vertex* rightDelete(Vertex* vertex, T key) {
		if (vertex == nullptr) { return nullptr; }

		if (key < vertex->value) {
			vertex->left = rightDelete(vertex->left, key);
			return vertex;
		}
		else if (key > vertex->value) {
			vertex->right = rightDelete(vertex->right, key);
			return vertex;
		}

		if (vertex->left == nullptr) { return vertex->right; }
		else if (vertex->right == nullptr) { return vertex->left; }
		else {
			T minKey = findMin(vertex->right)->value;
			vertex->value = minKey;
			vertex->right = rightDelete(vertex->right, minKey);
			return vertex;
		}

	}

	int getHeight(Vertex* vertex) {
		if (vertex == nullptr) {
			return 0;
		}
		return 1 + std::max(getHeight(vertex->left), getHeight(vertex->right));
	}

	int countVertices(Vertex* vertex) {
		if (vertex == nullptr) {
			return 0;
		}
		return 1 + countVertices(vertex->left) + countVertices(vertex->right);
	}

	void findVertAtLevel(Vertex* vertex, int currentLevel, int targetLevel, std::vector<T>& result) {
		if (vertex == nullptr) {
			return;
		}

		if (currentLevel == targetLevel) {
			int leftCount = countVertices(vertex->left);
			int rightCount = countVertices(vertex->right);

			if (leftCount > rightCount) {
				result.push_back(vertex->value);
			}
			return;
		}

		findVertAtLevel(vertex->left, currentLevel + 1, targetLevel, result);
		findVertAtLevel(vertex->right, currentLevel + 1, targetLevel, result);
	}
};

int main() {
	std::ifstream in("in.txt");
	std::ofstream out("out.txt");

	SearchBinTree<int> tree;
	int value;

	while (in >> value) {
		tree.SetVertex(value);
	}
	in.close();

	int H = tree.getHeight(tree.getRoot());
	int targetLevel = H / 2;

	std::vector<int> vertices;
	tree.findVertAtLevel(tree.getRoot(), 0, targetLevel, vertices);
	if (!vertices.empty() && vertices.size() % 2) {
		std::sort(vertices.begin(), vertices.end());
		int key = vertices[vertices.size() / 2];

		tree.setRoot(tree.rightDelete(tree.getRoot(), key));
	}
	tree.printDirectLeftBypass(out);
	out.close();

	return 0;
}
