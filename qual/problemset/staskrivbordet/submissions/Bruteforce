#include <algorithm>
using namespace std;

int height, n;
int h[25];
int bestSum = 100, best[2];

int main()
{
	scanf("%d%d", &height, &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", h + i);
	for (int j = 0; j < (1 << n); ++j){
		int sum = 0;
		for (int k = 0; k < n; ++k){
			if (j&(1 << k))
				sum += h[k];
		}
		if (sum == height){
			for (int m = j; m < (1 << n); m = (m + 1) | j){
				int sum2 = 0;
				for (int k = 0; k < n; ++k){
					if (!(m&(1 << k)))
						sum2 += h[k];
					if (sum2 > height)
						break;
				}
				if (sum2 == height){
					int usedN[2] = { 0, 0 };
					for (int k = 0; k < n; ++k){
						if (j&(1 << k))
							++usedN[0];
						else if (!(m&(1 << k)))
							++usedN[1];
					}
					if (usedN[0] + usedN[1] < bestSum){
						bestSum = usedN[0] + usedN[1];
						if (usedN[0] > usedN[1])
							swap(usedN[0], usedN[1]);
						best[0] = usedN[0];
						best[1] = usedN[1];
					}
				}
			}
		}
	}
	printf("%d %d\n", best[0], best[1]);
	return 0;
}

