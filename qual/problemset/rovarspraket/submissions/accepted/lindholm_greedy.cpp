#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<pair<char, int> > tokenize(string s) {
        vector<pair<char, int> > v;
        int N = (int)s.size();
        for (int i = 0; i < N; ++i) {
                char c = s[i];
                pair<char, int> pa(c, 1);
                if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'y' && c != 'u') {
                        while (i + 2 < N && s[i+1] == 'o' && s[i+2] == c)
                                i += 2, ++pa.second;
                }
                v.push_back(pa);
        }
        return v;
}

bool solve(string sa, string sb) {
        vector<pair<char, int> > a = tokenize(sa), b = tokenize(sb);
        if (a.size() != b.size())
                return false;
        int N = (int)a.size();
        for (int i = 0; i < N; ++i) {
                pair<char, int> pa = a[i], pb = b[i];
                if (pa.first != pb.first)
                        return false;
                int A = pa.second, B = pb.second;
                if (!(B <= A && A <= 2 * B))
                        return false;
        }
        return true;
}

int main() {
        string a, b;
        // NOTE: changed order here
        cin >> b >> a;
        cout << (solve(a, b) ? "ja" : "nej") << endl;
        return 0;
}
