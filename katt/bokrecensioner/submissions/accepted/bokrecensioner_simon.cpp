#include <iostream>
#include <vector>
using namespace std;

enum Rel {
	LE,
	LESS
};

struct Node {
	vector<pair<int, Rel>> ed;
	vector<pair<int, Rel>> red;
	bool visited;
	union {
		int time;
		int color;
	};
	Node() : visited(false), time(-1) {}
};

int N, M, K;
vector<Node> nodes;
vector<int> compValues;

void dfs1(int ind, int* times) {
	Node& n = nodes[ind];
	if (n.visited)
		return;
	n.visited = true;
	for (auto r : n.ed)
		dfs1(r.first, times);
	n.time = (*times)++;
}

void dfs2(int ind, int color) {
	Node& n = nodes[ind];
	n.visited = true;
	n.color = color;
	for (auto r : n.red) {
		Node& other = nodes[r.first];
		if (other.visited) {
			if (other.color != color) {
				int v = compValues[other.color];
				if (r.second == LESS)
					++v;
				compValues[color] = max(compValues[color], v);
			}
		}
		else {
			if (r.second == LESS)
				throw 1;
			dfs2(r.first, color);
		}
	}
}

int main() {
	cin >> N >> M >> K;
	string rel;
	nodes.resize(N);
	for (int i = 0; i < K; ++i) {
		int a, b;
		cin >> a >> rel >> b;
		--a, --b;
		if (rel == "=") {
			nodes[a].ed.emplace_back(b, LE);
			nodes[b].ed.emplace_back(a, LE);
			nodes[a].red.emplace_back(b, LE);
			nodes[b].red.emplace_back(a, LE);
		}
		else {
			Rel r = (rel == "<" ? LESS : LE);
			nodes[a].ed.emplace_back(b, r);
			nodes[b].red.emplace_back(a, r);
		}
	}

	int times = 0;
	for (int i = 0; i < N; ++i) {
		dfs1(i, &times);
	}

	vector<int> ordered(N);
	for (int i = 0; i < N; ++i) {
		nodes[i].visited = false;
		ordered[nodes[i].time] = i;
		nodes[i].color = -1;
	}
	try {
		int colors = 0;
		for (int i = N; i --> 0; ) {
			int ind = ordered[i];
			if (!nodes[ind].visited) {
				compValues.emplace_back(1);
				dfs2(ind, colors++);
			}
		}
		for (int i = 0; i < colors; ++i) {
			if (compValues[i] > M)
				throw 2;
		}
	}
	catch (int) {
		cout << -1 << endl;
		return 0;
	}

	for (int i = 0; i < N; ++i) {
		cout << compValues[nodes[i].color] << ' ';
	}
	cout << endl;

	return 0;
}
