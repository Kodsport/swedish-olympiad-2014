#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

const long long INF = 1LL << 60;

struct Node {
	long long size;
	vector<pair<long long, Node*>> downwards;
	Node* left;
	union {
		Node* right;
		string* str;
	};
	bool leaf() const { return !left; }
	bool rightDominates() const { return right->size > left->size; }
};

char getNthChar(Node* node, long long n);
char getNth(Node* node, long long n, int howfar, long long count) {
	howfar = min(howfar, (int)node->downwards.size());
	if (howfar == 0) {
		cout << "jumped " << count << ", then ";
		if (node->leaf()) {
			cout << "leaf " << node->str->size() << endl;
			return (*node->str)[(int)n];
		}
		assert((n < node->left->size) == node->rightDominates());
		cout << "turned at " << node->left->size << ' ' << node->right->size << endl;
		if (node->rightDominates())
			return getNthChar(node->left, n);
		else
			return getNthChar(node->right, n - node->left->size);
	}
	else {
		pair<long long, Node*> down = node->downwards[howfar-1];
		if (down.first <= n && n < down.first + down.second->size)
			return getNth(down.second, n - down.first, howfar - 1, count + (1 << (howfar - 1)));
		else
			return getNth(node, n, howfar - 1, count);
	}
}
char getNthChar(Node* node, long long n) {
	return getNth(node, n, node->downwards.size(), 0);
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
		if (n->leaf()) continue;
		n->downwards.push_back(n->rightDominates() ?
			make_pair(n->left->size, n->right) :
			make_pair(0LL, n->left));
	}

	for (Node* n : uniqueNodes) {
		if (n->leaf()) continue;
		vector<pair<long long, Node*> >& down = n->downwards;
		for (unsigned int i = 1; ; ++i) {
			pair<long long, Node*> a = down.back();
			if (a.second->downwards.size() < i) break;
			pair<long long, Node*> b = a.second->downwards[i-1];
			down.emplace_back(min(a.first + b.first, INF), b.second);
		}
	}

	Q = 1;
	for (int i = 0; i < Q; ++i) {
		long long q;
		cin >> q;
		--q;
		cout.put(getNthChar(topNode, q));
	}
	endl(cout);
}
