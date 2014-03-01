#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, T;

int getCount(const vector<int> &v) {
    int ans = 0;
    long long t = 0;
    for (int i = 0; i < N; ++i) {
        if (t + v[i] <= T) {
            ++ans;
            t += v[i];
        } else break;
    }
    return ans;
}

int main() {
    cin >> N >> T;

    vector<int> dists;

    for (int i = 0; i < N; ++i) {
        int x,y;
        cin >> x >> y;
        dists.push_back(2*abs(x) + 2*abs(y));
    }

    sort(dists.begin(), dists.end());

    int ans = 0;

    do {
        ans = max(ans, getCount(dists));
    } while (next_permutation(dists.begin(), dists.end()));

    cout << ans << endl;
}
