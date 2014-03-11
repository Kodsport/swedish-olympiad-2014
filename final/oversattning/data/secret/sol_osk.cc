#include <iostream>
#include <map>
#include <string>
#include <sstream>

using namespace std;

map<string,string> target;
map<string,string> to;
map<string,string> from;

string translate(const string &str) {
    if (target.find(str) != target.end()) return target[str];
    const string &nextWord = to[str];

    // found terminal word
    if (from[nextWord] == str) {
        target[str] = str;
        return str;
    }

    // keep going
    string terminalWord = translate(from[nextWord]);
    target[str] = terminalWord;
    return terminalWord;
}

int main() {
    int N;
    int M;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string l, r;
        cin >> l >> r;

        if (to.find(l) == to.end())
            to[l] = r;
        if (from.find(r) == from.end())
            from[r] = l;
    }

    cin >> M;
    string word;
    for (int i = 0; i < M; ++i) {
        cin >> word;
        cout << translate(word) << " ";
    }

    cout << endl;
}
