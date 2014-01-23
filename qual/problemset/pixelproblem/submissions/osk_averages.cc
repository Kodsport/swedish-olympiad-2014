#include <iostream>
#include <vector>

using namespace std;

vector<int> R, G, B;
int N;

long long getDiff(int p1, int p2) {
    long long avg1 = R[p1] + G[p1] + B[p1];
    avg1 /= 3;
    long long avg2 = R[p2] + G[p2] + B[p2];
    avg2 /= 3;
    return (avg1-avg2)*(avg1-avg2);
}

long long getSum(int w) {
    long long ret = 0;
    int h = N/w;
    for (int p = 0; p < N; ++p) {
        if (p >= w) ret += getDiff(p, p-w);
        if (p % w != 0) ret += getDiff(p, p-1);
    }
    return (N-w) * ret;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int r, g, b;
        cin >> r >> g >> b;
        R.push_back(r);
        G.push_back(g);
        B.push_back(b);
    }

    long long best = 1LL<<62;
    int bestw = -1;

    for (int w = 2; w < N; ++w) {
        if (N % w != 0) continue;
        long long cur = getSum(w);
        cout << "score " << cur << " for w = " << w << endl;
        if (cur < best) {
            int h = N/w;
            bestw = w;
            best = cur;
        }
    }

    cout << bestw << char(32) << N/bestw << endl;
}
