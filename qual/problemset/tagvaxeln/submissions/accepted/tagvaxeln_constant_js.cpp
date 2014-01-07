#include <cstdio>

int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	int ans = 2*(1439/b); //Det långsamma tåget måste först byta till sitt spår, sedan tillbaka
	if((1439/b)*b >= (1439/a)*a) ans--; // Det långsamma tåget har den sista avgången, så vi behöde inte ändra tillbaka
	printf("%d\n", ans);
}
