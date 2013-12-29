#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

int dp[1005][1005];

string a, b;

inline bool isConsonant(const char c) {
    return !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');
}

int isPossible(int x, int y) {
    if (x == a.size() && y == b.size()) {
        return 1;
    }
    if (x > a.size() || y > b.size()) return 0;
    int &ans = dp[x][y];
    if (ans != -1) return ans;
    ans = 0;
    if (a[x] == b[y])
        ans |= isPossible(x+1,y+1);
    if (isConsonant(a[x]) && a[x] == b[y] && y < b.size()-2 && b[y+1]=='o' && b[y] == b[y+2])
        ans |= isPossible(x+1,y+3);
    assert (0 <= ans <= 1);
    return ans;
}

int main() {
    cin >> a >> b;
    memset(dp, -1, sizeof(dp));
    if (isPossible(0,0))
        cout << "ja" << endl;
    else
        cout << "nej" << endl;
}
