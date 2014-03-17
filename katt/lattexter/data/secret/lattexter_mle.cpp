#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int N, Q;
	cin >> N >> Q;
	vector<string> strs;
	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		string str;
		if (a == 0) {
			cin >> str;
		}
		else {
			int b;
			cin >> b;
			str = strs[a-1] + strs[b-1];
		}
		strs.push_back(str);
	}
	string s = strs.back();

	for (int i = 0; i < Q; ++i) {
		int a;
		cin >> a;
		cout << s[a-1];
	}
	cout << endl;
}
