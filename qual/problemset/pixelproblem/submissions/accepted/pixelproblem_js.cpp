#include <cassert>
#include <cctype>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

int N;
vector<vector<int>> rgb;

double dist(int a, int b){
    double d = 0;
	for (int i = 0; i < 3; ++i){
		int dx = rgb[i][a] - rgb[i][b];
		d += abs(dx);
	}
	return d;
}

double badness(int b, bool mid){
	int h = rgb[0].size() / b;
	double score = 0;
	int count = 0;
	for (int i = 0; i <= 1000 && !mid; ++i){
		for (int j = 0; j <= 10; ++j){
			if (i + (j + 1)*b <= N){
				score += dist(i + j * b, i + (j + 1) * b);
				count++;
			}
		}
	}
	if (!mid && N <= 170000){
		for (int i = 0; i <= 1000; ++i){
			for (int j = h - 10; j < h - 1; ++j){
				if (i + (j + 1)*b >= 0 && i + (j + 1)*b <= N){
					score += dist(i + j * b, i + (j + 1) * b);
					count++;
				}
			}
		}
	}
	if (mid){
		for (int i = 0; i <= 1000; ++i){
			for (int j = h/2 - 5; j < h/2 + 5; ++j){
				if (i + (j + 1)*b >= 0 && i + (j + 1)*b <= N){
					score += dist(i + j * b, i + (j + 1) * b);
					count++;
				}
			}
		}
	}
	if (b < h){
		swap(b, h);
	}
	score /= count;
	return score;
}

int main(){

	cin >> N;
	rgb.assign(3, vector<int>(N));
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < 3; ++j){
			cin >> rgb[j][i];
		}
	}
	double best = 1e300;
	int bestB = 0;
	for (int b = 50; b < N / 50; b++){
		double newBad = badness(b, false);
		if (newBad < best){
			best = newBad;
			bestB = b;
		}
	}
	if (best == 0){
		best = 1e300;
		bestB = 0;
		for (int b = 50; b < N / 50; b++){
			double newBad = badness(b, true);
			if (newBad < best){
				best = newBad;
				bestB = b;
			}
		}
	}
	cout << bestB << endl;
}
