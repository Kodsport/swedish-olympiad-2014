#include <iostream>
#include <string>

using namespace std;

int main() {

    string str;
    cin >> str;
    for (int i = 0; i < str.size(); ++i) {
        str[i] -= '0';
    }

    int ans = 0;

    for (int i = 1; i < (1<<str.size()); ++i) {
        unsigned long long x = 0;
        for (int j = 0; j < str.size(); ++j) {
            if (i & (1<<j)) x = x*10 + str[j];
        }
        if (x % 3 == 0) ++ ans;
    }

    cout << ans << endl;
}
