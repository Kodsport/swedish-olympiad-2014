#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

string c[] = {"V", "V", "V", "H", "H", "H", "U", "U", "U", "N", "N", "N", "VH", "VU", "VN", "HU", "HN", "UN"};

int main(int argc, char** argv){
	if(argc < 4){
		printf("./gen <n> <seed> <0|1: single>\n");
		exit(1);
	}
	int n, seed, single;
	n = atoi(argv[1]);
	single = atoi(argv[2]);
	seed = atoi(argv[3]);
	srand(seed);
	printf("%d\n", n);
	for(int i = 0; i < n; i++){
		cout << c[rand()%(single ? 12 : 18)] << endl;
	}
}
