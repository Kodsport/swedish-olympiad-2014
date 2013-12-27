#include <map>
#include <iostream>
#include <cstdio>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> result(N,0);
    map<int, vector<pair<int,int> > > ads;

    cin.ignore();
    for (int i = 0; i < N; ++i) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int k;
        ss >> k;
        string word;
        for (int j = 0; j < k; ++j) {
            ss >> word;
            int sh,sm,eh,em;
            sscanf(word.c_str(), "%d:%d-%d:%d", &sh, &sm, &eh, &em);
            int st = sh*60 + sm;
            int et = eh*60 + em;
            ads[i].push_back(make_pair(st,et));
        }
    }

    int cc = 0;
    for (int t = 0; t < 3600; ++t) {
        vector<pair<int,int> > &ads_list = ads[cc];
        bool switched = false;
        for (int i = 0; i < ads_list.size(); ++i) {
            if (t < ads_list[i].second && t >= ads_list[i].first) {
                cc = (cc+1) % N; // assuming switching channel takes 1 minute
                switched = true;
                break;
            }
        }
        result[cc] += !switched;
    }

    for (int i = 0; i < N; ++i) {
        cout << result[i] << endl;
    }
}
