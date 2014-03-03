#include <iostream>
#include <cassert>
#include <cstring>
#include <string>

using namespace std;

const long long MOD = 1000000007;

long long dp[100005][5];

long long ways(const string &str, int pos, int sum) {
    if (pos == str.size()) return sum == 0;
    long long &ret = dp[pos][sum];
    if (ret != -1) return ret;
    return ret = (ways(str, pos+1, (sum + str[pos]) % 3) + ways(str, pos+1, sum)) % MOD;
}

int main() {
    assert(MOD == 1e9 + 7);
    string number;
    cin >> number;
    for (int i = 0; i < number.size(); ++i)
        number[i] -= '0';
    memset(dp,-1,sizeof(dp));
    cout << (ways(number, 0, 0)) << endl;
}
