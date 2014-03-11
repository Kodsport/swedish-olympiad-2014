#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
int m3(int n) {
        return ((n % 3) + 3) % 3;
}
 
int main() {
        string str;
        getline(cin, str);
        reverse(str.begin(), str.end());
        vector<int> sol(3, 0), next;
        sol[0] = 1;
        int res = 0;
        for (char c : str) {
                int d = c - '0';
                if (d != 0)
                        res += sol[m3(-d)];
                else
                        ++res;
                next = sol;
                for (int i = 0; i < 3; ++i)
                        next[m3(i + d)] += sol[i];
                next.swap(sol);
        }
        cout << res << endl;
}
