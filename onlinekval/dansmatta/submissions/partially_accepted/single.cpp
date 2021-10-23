#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

#define rep(i, a, b) for(int i = int(a); i < int(b); ++i) 
typedef vector<int> vi;

const int MOVES = 6;
int n, down[] = {0b0011, 0b0101, 0b1001, 0b0110, 0b1010, 0b1100}, chr[256];

int main(){
	chr['U'] = 1; chr['H'] = 2; chr['N'] = 4; chr['V'] = 8;
	cin >> n;
	vector<vi> best(2, vi(MOVES, 1000000));
	best[1][4] = 0;
	rep(i,0,n){
		string s;
		cin >> s; 
		int to = chr[s[0]];
		rep(j,0,MOVES) rep(k,0,MOVES) if((down[j]|to)==down[j]) best[i%2][j] = min(best[i%2][j], best[1-(i%2)][k] + __builtin_popcount(down[j]^down[k])/2);
		best[1-(i%2)] = vi(MOVES, 1000000);
	}
	cout << *min_element(best[(n-1)%2].begin(), best[(n-1)%2].end()) << endl;
}
