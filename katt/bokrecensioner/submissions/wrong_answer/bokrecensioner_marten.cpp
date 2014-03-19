#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#define MAXN 1000005
using namespace std;

vector<int> ls[MAXN], gr[MAXN];
vector<bool> strict[MAXN];
bool inStack[MAXN];
int sccBelong[MAXN];
vector<int> scc[MAXN];
vector<int> sccOut[MAXN];
vector<bool> sccOutStrict[MAXN];
int sccIn[MAXN];
int minRating[MAXN];
int rating[MAXN];
bool processed[MAXN];

void addEdge(int a, int b, bool s){
	ls[a].push_back(b);
	gr[b].push_back(a);
	strict[a].push_back(s);
}

int main(){
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i=0; i < k; ++i){
		int a, b;
		char c[3];
		scanf("%d%s%d", &a, c, &b);
		--a;
		--b;
		if(c[0] == '='){
			addEdge(a, b, 0);
			addEdge(b, a, 0);
		}
		else if(c[1] == '='){
			addEdge(a, b, 0);
		}
		else{
			addEdge(a, b, 1);
		}
	}
	stack<int> S;
	stack<int> process;
	for(int i=0; i < n; ++i)
		process.push(i);
	while(!process.empty()){
		int i=process.top();
		process.pop();
		if(i < 0){
			if(!inStack[-i-1]){
				inStack[-i-1]=1;
				S.push(-i-1);
			}
			continue;
		}
		if(processed[i])
			continue;
		process.push(-i-1);
		for(int j=0; j < ls[i].size(); ++j){
			process.push(ls[i][j]);
		}
		processed[i]=1;
	}
	int sccN = 0;
	while(!S.empty()){
		int i=S.top();
		S.pop();
		stack<int> dfs;
		dfs.push(i);
		while(!dfs.empty()){
			int j=dfs.top();
			dfs.pop();
			if(!inStack[j])
				continue;
			sccBelong[j]=sccN;
			scc[sccN].push_back(j);
			inStack[j]=0;
			for(int k=0; k < gr[j].size(); ++k)
				dfs.push(gr[j][k]);
		}
		minRating[sccN]=1;
		++sccN;
	}
	for(int i=0; i < sccN; ++i)
		for(int j=0; j < scc[i].size(); ++j){
			int m=scc[i][j];
			for(int k=0; k < ls[m].size(); ++k){
				if(sccBelong[ls[m][k]] == i)
					continue;
				sccOut[i].push_back(sccBelong[ls[m][k]]);
				sccOutStrict[i].push_back(strict[m][k]);
				++sccIn[sccBelong[ls[m][k]]];
			}
		}
	stack<int> sccStack;
	for(int i=0; i < sccN; ++i)
		if(!sccIn[i])
			sccStack.push(i);
	while(!sccStack.empty()){
		int i = sccStack.top();
		sccStack.pop();
		rating[i]=minRating[i];
		for(int j=0; j < sccOut[i].size(); ++j){
			int to=sccOut[i][j];
			--sccIn[to];
			minRating[to]=max(minRating[to], rating[i]+sccOutStrict[i][j]);
			if(!sccIn[to])
				sccStack.push(to);
		}
	}
	bool ok=1;
	for(int i=0; i < sccN; ++i)
		if(!rating[i] || rating[i] > m)
			ok=0;
	if(!ok)
		printf("-1\n");
	else {
		for(int i=0; i < n; ++i)
			printf("%d ", rating[sccBelong[i]]);
		puts("");
	}
}
