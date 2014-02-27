#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, T;
    cin >> N >> T;
    vector<int> v;
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        v.push_back(x+y);
    }
    sort(v.begin(), v.end());
    int ans = 0;
    int t = 0;
    for (int i = 0; i < N; ++i) {
        if (t + v[i] <= T) {
            ++ans;
            t += v[i];
        } else break;
    }
    cout << ans << endl;
}
