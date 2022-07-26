#include <cstdio>
#include <vector>
#include <algorithm>
#define rep(i, a, b) for(int i=int(a); i<int(b); i++)

using namespace std;
typedef int ll;

vector<ll> colors;
int N, K;

bool is_possible(ll D) {
	int count = 0;
	rep(i, 0, N-1) {
		if(abs(colors[i]-colors[i+1]) < D) {
			count++;
			i++;
		}
	}
	return (count >= K);
}

ll binsearch(ll a, ll b) {
	ll low = a;
	ll high = b;

	while(low < high) {
		ll mid = low + (high-low)/2;
		if(is_possible(mid)) {
			high = mid;
		} else {
			low = mid+1;
		}
	}

	return low;
}

int main() {
	scanf("%d %d", &N, &K);

	ll maxF = 0;
	rep(i, 0, N) {
		ll in;
		scanf("%d", &in);
		maxF = max(maxF, in);
		colors.push_back(in);
	}
	sort(colors.begin(), colors.end());
	printf("%d\n", binsearch(0, maxF));
	return 0;
}
