#include<iostream>

using namespace std;
typedef long long ll;


bool ok(string& s, ll from, ll to){
	ll v = 0;
	for(ll i = from; i < to; i++) v = 10*v + s[i] - '0';
	return v ? (v <= 255 && s[from] != '0') : to-from == 1;
}

int main(){
	string ip;
	cin >> ip;
	ll ans = 0;
	for(ll i = 1; i < ip.size(); i++)
		for(ll j = i+1; j < ip.size(); j++)
			for(ll k = j+1; k < ip.size(); k++){
				if(ok(ip, 0, i) && ok(ip, i, j) && ok(ip, j, k) && ok(ip, k, ip.size())) ans++;
			}
	cout << ans << endl;
}
