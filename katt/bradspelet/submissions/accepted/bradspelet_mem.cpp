#include <cstdio>
#include <cassert>
#include <algorithm>
#define rep(i, a, b) for(int i=int(a); i<int(b); i++)

using namespace std;

const int MAX_NM = 1000;
bool dp[MAX_NM][MAX_NM][2];
bool isset[MAX_NM][MAX_NM][2];

bool rek2(int h, int b, int t, int cut, bool hor);

//Vem vinner om vi är i statet med ett bräde av storlek h*b
// och nästa drag är att spelare t skall hugga brädet?
bool rek(int h, int b, int t) {
	if(h == 1 && b == 1)
		return !t;
	if(isset[h][b][t])
		return dp[h][b][t];

	bool winner = !t;
	rep(h2, 1, h) {
		if(rek2(h, b, !t, h2, true) == t)
			winner = t;
	}
	rep(b2, 1, b) {
		if(rek2(h, b, !t, b2, false) == t)
			winner = t;
	}

	dp[h][b][t] = winner;
	isset[h][b][t] = true;
	return winner;
}

//Vem vinner om vi är i statet där vi har ett h*b-bräde som är
// delat i två delar vid cut, där snittet är horisontellt omm
// hor==true, och nästa drag är att spelare t ska välja vilken
// bit som skall vara kvar?
bool rek2(int h, int b, int t, int cut, bool hor) {
	if(hor) {
		if(rek(cut, b, t) == t)
			return t;
		if(rek(h-cut, b, t) == t)
			return t;
	}
	else {
		if(rek(h, cut, t) == t)
			return t;
		if(rek(h, b-cut, t) == t)
			return t;
	}
	return !t;
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	printf("%c\n", rek(N, M, 0)?'B':'A');
	return 0;
}
