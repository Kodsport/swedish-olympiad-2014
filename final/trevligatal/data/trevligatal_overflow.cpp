#include <cstdio>
#include <cstdlib>
#define MOD 1000000000
using namespace std;

char input[100005];

int main(){
	
	int testN=0;
	while(true){
		++testN;

        int l=100000;
        input[0]='3';
        for(int i=1; i < l; ++i){
            input[i]=rand()%10+'0';
            if(rand()%2)
                input[i]='0';
	}
	input[l]=0;
	int dp[2][2][3];
	dp[0][0][0]=1;
	dp[0][0][1]=0;
	dp[0][0][2]=0;
	dp[0][1][0]=0;
	dp[0][1][1]=0;
	dp[0][1][2]=0;
	int len;
	for(len=0; input[len]; ++len);
	bool read=1, write=0;
	int ans=0;
	for(int i=len-1; i >= 0; --i){
		read^=1;
		write^=1;
		int m=(input[i]-'0')%3;
		bool zero=(input[i]=='0');
		ans += zero;
		for(int j=0; j < 3; ++j){
			int from=(j-m+3)%3;
			dp[write][0][j]=dp[read][0][j];
			dp[write][1][j]=dp[read][1][j];
			dp[write][!zero][j]=((dp[write][!zero][j]+dp[read][0][from])%MOD+dp[read][1][from])%MOD;
		}
	}
	ans=(ans+dp[write][1][0]);
	if(ans >= MOD){
		printf("%s\n", input);
		break;
	}
	//printf("%d\n", ans);
	/*printf("%d\n", ans);*/}
}
