#include <iostream>
#include <fstream>
#include <vector>

template <typename T>
class SearchBinTree {
private:
	struct Vertex {
		T value;
		Vertex* left = nullptr;
		Vertex* right = nullptr;

		Vertex(int x) {
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

public:
	SearchBinTree(int count) {
		this->count = count;
	}
	SearchBinTree() {}

	Vertex* getRoot() {
		return root;
	}

	void SetVertex(int x) {
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

	std::vector<T>& directLeftBypass(std::vector<T> vec) {

	}

	void printDirectLeftBypass(std::ofstream& out) {
		if (root != nullptr) {
			root->printDirectLeftBypass(out);
		}
	}
};

int main() {
	std::ifstream in("input.txt");
	std::ofstream out("output.txt");

	int value;
	SearchBinTree<int> tree;

	while (in >> value) {
		tree.SetVertex(value);
	}
	in.close();

	tree.printDirectLeftBypass(out);
	out.close();

}