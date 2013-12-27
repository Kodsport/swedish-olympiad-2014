#include <iostream>
#include <string>

using namespace std;

inline bool isConsonant (const char c) {
    return !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');
}

int main() {
    string from, to;
    cin >> from >> to;

    int i = 0;
    int j = 0;

    for (; i < from.size() && j < to.size(); ++i, ++j) {
        if ((i < from.size() - 1 && j < to.size()-1 && from[i+1] != to[j+1])
                || (i == from.size()-1 && j < to.size()-2)) {
            if (isConsonant(from[i]) && j < to.size()-2 && to[j] == to[j+2] && to[j+1] == 'o') {
                j += 2;
            } else {
                break;
            }
        }
    }

    if (i == from.size() && j == to.size()) {
        cout << "ja" << endl;
    } else {
        cout << "nej" << endl;
    }
}
