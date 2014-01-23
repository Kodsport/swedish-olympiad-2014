#include <iostream>
#include <vector>
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

    pair<double, int> best(1 << 29, 0);
    for (int side = 2; side < N; ++side) {
        if (N % side) continue;
        int side2 = N / side;
        double d = 0;
int count = 0;
        for (int i = 0; i < side; ++i) {
            for (int j = 0; j < side2; ++j) {
                if (i) d += compare(v[i + j * side], v[(i-1) + j*side]), count++;
                if (j) d += compare(v[i + j * side], v[i + (j-1)*side]), count++;
            }
        }
d /= count;
        best = min(best, make_pair(d, side));
    }

    cout << best.second << ' ' << (N / best.second) << endl;
    return 0;
}
