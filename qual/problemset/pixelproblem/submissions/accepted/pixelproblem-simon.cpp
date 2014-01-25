#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Pixel {
	int r, g, b;
};

int compare(Pixel a, Pixel b) {
	return abs(a.r - b.r) + abs(a.g - b.g) + abs(a.b - b.b);
}

int main() {
	int N;
	cin >> N;
	vector<Pixel> v(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i].r >> v[i].g >> v[i].b;

	pair<double, int> best(1e100, 0);
	int to = min(N/3, (int)(sqrt(N) * 3));
	for (int side = 11; side < to; ++side) {
		double d = 0;
		int count = 0;
		for (int j = 1; ; ++j) {
			for (int i = 1; i < side / 1; ++i) {
				d += compare(v[i + j * side], v[(i-1) + j * side]);
				d += compare(v[i + j * side], v[i + (j-1) * side]);
				if (++count > N * 10 / 26) goto out;
			}
		}
out:;
		d /= count;
		best = min(best, make_pair(d, side));
	}

	cout << best.second << endl;
	return 0;
}
