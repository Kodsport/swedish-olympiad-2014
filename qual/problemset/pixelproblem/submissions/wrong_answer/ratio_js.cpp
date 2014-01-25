#include <cstdio>
#include <cmath>

double ratio = 16.0/10.0;


int main(){
	int n;
	scanf("%d", &n);
	int b, h;
	double bestr = 1000000;
	for(int i = 2; i < n; ++i){
		if(n%i == 0){
			int bb = i;
			int hh = n/i;
			double r = (bb+0.0)/hh;
			if(fabs(r-ratio) < fabs(bestr-ratio)){
				b = bb;
				h = hh;
				bestr = r;
			}
		}
	}
	printf("%d %d\n", b, h);
}
