#include <iostream>
#include <fstream>
#include <vector>
#include <string>

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

};

int main() {

}