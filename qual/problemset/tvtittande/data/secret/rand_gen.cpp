#include <vector>
#include <cstdio>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int N;
    cin >> N;
    double P;
    cin >> P;
    string salt;
    cin >> salt;

    int s = 0;
    for (int i = 0; i < salt.size(); ++i) s += salt[i];

    srand(s);

    vector<vector<bool> > breaks(N, vector<bool>(60*24+1, false));

    cout << N << endl;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 60*24; ++j) {
            double x = double(rand()) / RAND_MAX;
            if (x < P + 1e-9) breaks[i][j] = true;
        }
    }

    vector<vector<pair<int,int> > > v(N);

    for (int i = 0; i < N; ++i) {
        bool in = false;
        int start;
        for (int j = 0; j < 60*24+1; ++j) {
            if (breaks[i][j]) {
                if (!in) {
                    start = j;
                    in = true;
                }
            } else {
                if (in) {
                    in = false;
                    v[i].push_back(make_pair(start, j-1));
                }
            }
        }
    }

    for (int i = 0; i < v.size(); ++i) {
        cout << v[i].size();
        if (v[i].size()) cout << " ";
        for (int j = 0; j < v[i].size(); ++j) {
            if (j) cout << " ";
            int s = v[i][j].first;
            int e = v[i][j].second;
            printf("%02d:%02d-%02d:%02d",s/60,s%60,e/60,e%60);
        }
        cout << endl;
    }

}
