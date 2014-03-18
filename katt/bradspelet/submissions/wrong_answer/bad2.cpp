#include <cstdio>
#include <cassert>
#include <algorithm>
#define rep(i, a, b) for(int i=int(a); i<int(b); i++)
 
using namespace std;
 
const int MAX_N = 1000;
const int MAX_M = 1000;
bool dp[MAX_N][MAX_M][2];
 
int main() {
        int N, M;
        scanf("%d %d", &N, &M);
        printf("%c\n", (N==M)?'B':'A');
        return 0;
}
