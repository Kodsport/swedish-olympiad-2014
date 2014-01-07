#include<iostream>

using namespace std;

bool ok(string& s, int from, int to){
	int v = 0;
	for(int i = from; i < to; i++) v = 10*v + s[i] - '0';
	return v ? (v <= 255 && s[from] != '0') : to-from == 1;
}

int main(){
	string ip;
	cin >> ip;
	int ans = 0;
	for(int i = 1; i < ip.size(); i++)
		for(int j = i+1; j < ip.size(); j++)
			for(int k = j+1; k < ip.size(); k++){
				if(ok(ip, 0, i) && ok(ip, i, j) && ok(ip, j, k) && ok(ip, k, ip.size())) ans++;
			}
	cout << ans << endl;
}
