//Problem: flygbussen
//Komplexitet: O(NK)

#include <cstdio>
#include <algorithm>
#define MAXN 50005
#define MAXK 105
#define INF 1LL<<60
using namespace std;

long long timeSum[MAXN*MAXK];
int timeFactor[MAXN*MAXK];
long long dp[MAXN*MAXK];
int N, K;
int input[MAXN];

long long getTimeSum(int j, long long t){
	return timeSum[j] + timeFactor[j] * t;
}

int main()
{
	scanf("%d%d", &N, &K);
	K *= 2;
	for (int i = 0; i < N; ++i)
		scanf("%d", input+i);
	sort(input, input + N);
	int curInd = 0;
	int j = K;
	long long ans = INF;
	for (int t = input[0]; t <= input[N - 1] + K; ++t, ++j){
		timeSum[j] = timeSum[j - 1];
		timeFactor[j] = timeFactor[j - 1];
		bool processProperly = false;
		while (curInd < N && input[curInd] <= t){
			++timeFactor[j];
			timeSum[j] -= input[curInd];
			++curInd;
			processProperly = true;
		}
		if (curInd < N && t < input[curInd] - K && t > input[curInd-1]+K)
			t = input[curInd] - K;
		dp[j] = INF;
		if (processProperly){
			for (int k = j - K; k >= 0 && k > j - 2 * K; --k){
				dp[j] = min(dp[j], dp[k] + getTimeSum(j, t) - getTimeSum(k, t));
			}
		}
		else
			dp[j] = dp[j - K] + getTimeSum(j, t) - getTimeSum(j - K, t);
		if (curInd == N)
			ans = min(ans, dp[j]);
	}
	printf("%lld\n", ans);
	return 0;
}
