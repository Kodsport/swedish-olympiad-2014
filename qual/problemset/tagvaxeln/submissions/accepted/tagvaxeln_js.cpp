#include <cstdio>

int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	int ans = 0;
	bool s = 0;
	for(int i = 1; i <= 1439; i++){
		if(i%a == 0 && i%b == 0){
			ans++;
			s = !s;
		} else if(i%a == 0){
			ans += s;
			s = false;
		} else if(i%b == 0){
			ans += !s;
			s = true;
		}
	}
	printf("%d\n", ans);
}
