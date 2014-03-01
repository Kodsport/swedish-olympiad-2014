#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, T;
    cin >> N >> T;
    vector<long long> v;
    for (int i = 0; i < N; ++i) {
        long long x, y;
        cin >> x >> y;
        v.push_back(2*abs(x)+2*abs(y));
    }
    sort(v.begin(), v.end());
    int ans = 0;
    long long t = 0;
    for (int i = 0; i < N; ++i) {
        if (t + v[i] <= T) {
            ++ans;
            t += v[i];
        } else break;
    }
    cout << ans << endl;
}
