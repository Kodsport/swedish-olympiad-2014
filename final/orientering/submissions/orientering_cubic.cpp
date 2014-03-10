#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Pos {
	int x, y;
};

int main() {
	int W, H, X, Y;
	cin >> H >> W >> Y >> X;
	vector<string> board(H+2);
	for (int i = 0; i < H; ++i) {
		string line;
		cin >> line;
		board[i+1] = '#' + line + '#';
	}
	board[0] = board[H+1] = string(W+2, '#');
	board[1][0] = '>';
	Pos p0 = {0, 1};
	vector<vector<bool> > seen(H+2, vector<bool>(W+2, false));
	const int LIM = H * W * 4;
	vector<vector<Pos> > q(LIM + max(H, W));
	q[0].push_back(p0);
	int res = 1 << 29;
	for (int dist = 0; dist < LIM; ++dist) {
		vector<Pos>& v = q[dist];
		for (int pi = 0; pi < (int)v.size(); ++pi) {
			Pos p = v[pi];
			int x = p.x, y = p.y;
			if (seen[y][x]) continue;
			seen[y][x] = true;

			char c = board[y][x];
			int dx, dy;
			switch (c) {
				case 'v': dx = 0, dy = 1; break;
				case '^': dx = 0, dy = -1; break;
				case '<': dx = -1, dy = 0; break;
				case '>': dx = 1, dy = 0; break;
				default: cout << -1 << endl; return 1;
			}

			if (dist == 0 && pi == 0) board[y][x] = '#'; // cover the hole again

			// Start running!
			int dist2 = dist;
			if (x == X || y == Y) {
				for (;;) {
					x += dx;
					y += dy;
					char c2 = board[y][x];
					if (c2 == '#')
						break;
					if (x == X && y == Y) {
						res = min(res, dist2);
					}
					if (c2 != '.') {
						Pos p2 = {x, y};
						q[dist2].push_back(p2);
						++dist2;
					}
				}
			}
			else {
#define LOOP(dx, dy) do { \
					for (;;) { \
						x += dx; \
						y += dy; \
						char c2 = board[y][x]; \
						switch (c2) { \
						case '.': \
							break; \
						case '#': \
							goto quitloop; \
						default: \
							{ \
								Pos p2 = {x, y}; \
								q[dist2].push_back(p2); \
								/* uncomment for linear time: */ \
								/* if (board[y][x] == board[p.y][p.x]) goto quitloop; */ \
								++dist2; \
							} \
						} \
					} \
				} while(0)

				if (dx == 1) LOOP(1, 0);
				else if (dx == -1) LOOP(-1, 0);
				else if (dy == 1) LOOP(0, 1);
				else if (dy == -1) LOOP(0, -1);
quitloop:;
			}
		}
	}
	cout << res << endl;
	return 0;
}
