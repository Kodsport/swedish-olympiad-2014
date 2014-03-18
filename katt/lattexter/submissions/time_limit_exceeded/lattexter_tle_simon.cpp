#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

const long long INF = 1LL << 60;

struct Node {
	long long size;
	long long dominantLeft;
	Node* dominantNode;
	Node* left;
	union {
		Node* right;
		string* str;
	};
	bool leaf() const { return !left; }
	bool rightDominates() const { return right->size > left->size; }
};

char getNth(Node* node, long long n) {
	while (node->dominantLeft <= n && n < node->dominantLeft + node->dominantNode->size) {
		n -= node->dominantLeft;
		node = node->dominantNode;
	}

	if (node->leaf())
		return (*node->str)[(int)n];
	if (n < node->left->size)
		return getNth(node->left, n);
	else
		return getNth(node->right, n - node->left->size);
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	int N, Q;
	cin >> N >> Q;
	vector<Node*> nodes(N), uniqueNodes;
	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		if (a) {
			int b;
			cin >> b;
			--a, --b;
			if (nodes[a]->size == INF) {
				nodes[i] = nodes[a];
			}
			else {
				Node* n = nodes[i] = new Node;
				n->size = min(nodes[a]->size + nodes[b]->size, INF);
				n->left = nodes[a];
				n->right = nodes[b];
				uniqueNodes.push_back(n);
			}
		}
		else {
			string* str = new string;
			cin >> *str;
			nodes[i] = new Node;
			nodes[i]->size = str->size();
			nodes[i]->left = nullptr;
			nodes[i]->str = str;
			uniqueNodes.push_back(nodes[i]);
		}
	}
	Node* topNode = nodes[N-1];

	for (Node* n : uniqueNodes) {
		if (n->leaf()) {
			n->dominantLeft = INF;
		}
		else {
			n->dominantLeft = (n->rightDominates() ? n->left->size : 0LL);
			n->dominantNode = (n->rightDominates() ? n->right : n->left);
		}
	}

	for (int i = 0; i < Q; ++i) {
		long long q;
		cin >> q;
		--q;
		cout.put(getNth(topNode, q));
	}
	endl(cout);
}
