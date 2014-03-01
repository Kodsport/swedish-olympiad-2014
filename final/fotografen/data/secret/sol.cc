#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

int main() {
    int N, k;
    cin >> N >> k;
    string input;
    cin >> input;
    vector<int> v;
    for (int i = 0; i < input.size(); ++i) {
        const char &c = input[i];
        if (c == 'U') v.push_back(0);
        else if (c == 'H') v.push_back(1);
        else if (c == 'N') v.push_back(2);
        else if (c == 'V') v.push_back(3);
        else assert(0);
    }
    vector<int> sweep(v.size(),0);
    int curAdd = 0;
    int ops = 0;
    bool fail = false;
    for (int i = 0; i < input.size(); ++i) {
        curAdd = (curAdd + sweep[i]) % 4;
        int curRot = (v[i] + curAdd) % 4;
        int added = curRot == 0 ? 0 : 4 - curRot;
        if (added > 0) {
            curAdd = (curAdd + added) % 4;
            if (i + k - 1 >= v.size()) {
                fail = true;
                break;
            }
            if (i + k < v.size()) sweep[i + k] += (4 - added);
        }
        ops += added;
    }
    if (fail) cout << -1 << endl;
    else cout << ops << endl;
}
