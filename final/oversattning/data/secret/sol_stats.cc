#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>

using namespace std;

map<string, pair<string, int> > target;
map<string, string> to;
map<string, string> from;

pair<string, int> translate(const string &str) {
	pair<string, int>& out = target[str];
    if (out.first.empty()) {
		string nextWord = to[str];
		string back = from[nextWord];

		if (back == str) {
			// found terminal word
			out = make_pair(str, 0);
		}
		else {
			// keep going
			out = translate(back);
			++out.second;
		}
	}
    return out;
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string l, r;
        cin >> l >> r;

        if (to.find(l) == to.end())
            to[l] = r;
        if (from.find(r) == from.end())
            from[r] = l;
    }

    string word;
	int max = 0;
	vector<int> table;
    while (cin >> word) {
		pair<string, int> pa = translate(word);
		int c = pa.second;
		if (c >= table.size()) table.resize(c+1);
		++table[c];
		// cout << pa.second << ' ';
        // cout << pa.first << " ";
		max = std::max(max, pa.second);
    }
    cout << endl;
	for (int i = 0; i < (int)table.size(); ++i)
		cout << table[i] << ' ';
	cout << endl;
	// cout << max << endl;
}
