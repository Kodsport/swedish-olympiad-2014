#pragma GCC optimize("O3")
#include <bits/allocator.h>
#pragma GCC target ("avx2,aes,abm,bmi,bmi2,popcnt,lzcnt")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using p2 = pair<ll, ll>;
const ll inf = 1e18;

#define rep(i,n) for (ll i = 0; i < (n); i++)
#define repp(i,a,n) for (ll i = (a); i < (n); i++)
#define repe(i, arr) for (auto& i : arr)
#define all(x) begin(x),end(x)
#define sz(x) ((ll)(x).size())


constexpr int N_DIRECTIONS = 4;
constexpr int FACE_UP = 0;
const string DIRECTIONS = "UHNV";

static inline int get_rotations_to_face_up(const int rotation) {
	return rotation == FACE_UP ? 0 : 4 - rotation;
}

ll ops = 0;
static inline int rotate_section(vector<char>& orientations, int start, int end)
{
	int rotations = get_rotations_to_face_up(orientations[start]);

	repp(i, start, end)
	{
        ops++;
		orientations[i] = (orientations[i] + rotations) % N_DIRECTIONS;
	}

	return rotations;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	int N,k;
	cin >> N >> k;
	string startString;
	cin >> startString;
	vector<char> orientations(N);

	rep(i, N)
	{
		orientations[i] = DIRECTIONS.find(startString[i]);
	}

	int totalRotations = 0;

	rep(i, N - k + 1) {
		if (orientations[i] == FACE_UP) {
			continue;
		}

		totalRotations += rotate_section(orientations, i, i + k);
	}
    cerr << ops << endl;

	repp(i, N - k + 1, N)
	{
		if (orientations[i] != FACE_UP)
		{
			cout << "-1\n";
			return 0;
		}
	}

	cout << totalRotations << '\n';
	return 0;
}
