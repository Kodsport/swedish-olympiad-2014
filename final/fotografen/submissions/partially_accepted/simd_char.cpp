#undef _GLIBCXX_DEBUG                // disable run-time bound checking, etc
#pragma GCC optimize("Ofast,inline") // Ofast = O3,fast-math,allow-store-data-races,no-protect-parens
#pragma GCC optimize ("unroll-loops")

#pragma GCC target("bmi,bmi2,lzcnt,popcnt")                      // bit manipulation
#pragma GCC target("movbe")                                      // byte swap
#pragma GCC target("aes,pclmul,rdrnd")                           // encryption
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4.1,sse4.2") // SIMD


#include "bits/stdc++.h"

using namespace std;


#define enablell 0

#if enablell
#define int long long
constexpr int inf = int(1e18);
#define float double
#else
constexpr int inf = int(2e9);
#endif


// Type shorthands
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vvb> vvvb;
typedef pair<int, int> p2;
typedef vector<p2> vp2;
typedef vector<vp2> vvp2;
typedef vector<vvp2> vvvp2;
typedef tuple<int, int, int> p3;
typedef vector<p3> vp3;
typedef vector<vp3> vvp3;
typedef vector<vvp3> vvvp3;
typedef tuple<int, int, int, int> p4;
typedef vector<p4> vp4;

// Input shorthands
template <typename T> inline void read(T& a) { cin >> a; }
template <typename T> inline void read(T& a, T& b) { cin >> a >> b; }
template <typename T> inline void read(T& a, T& b, T& c) { cin >> a >> b >> c; }
#define tread(type, a) type a; read(a)
#define tread2(type, a, b) tread(type, a); tread(type, b)
#define tread3(type, a, b, c) tread2(type, a, b); tread(type, c)
#define tread4(type, a, b, c, d) tread3(type, a, b, c); tread(type, d)
#define tread5(type, a, b, c, d, e) tread4(type, a, b, c, d); tread(type, e)
#define readvector(type, name, size) vector<type> name(size); rep(i,size) {tread(type,temp); name[i]=temp;}

// Output shorthands
template <typename T> inline void write(const T& a) { cout << a; }
template <typename T> inline void writeline(const T& a) { cout << a << "\n"; }

// Pair operations
template<typename T, typename U> inline T first(const U& a) { return *begin(a); }
template <typename T, typename U> inline void operator+=(pair<T, U>& l, const pair<T, U>& r) { l = { l.first + r.first,l.second + r.second }; }
template <typename T, typename U> inline pair<T, U> operator+(const pair<T, U> l, const pair<T, U> r) { return { l.first + r.first, l.second + r.second }; }
template <typename T, typename U> inline pair<T, U> operator-(const pair<T, U> l, const pair<T, U> r) { return { l.first - r.first, l.second - r.second }; }
template <typename T, typename U> inline pair<T, U> operator*(const pair<T, U> l, const int m) { return { l.first * m, l.second * m }; }

// String operations
template <typename Out> inline void split(const string& s, char delim, Out result) { istringstream iss(s); string item; while (getline(iss, item, delim)) { *result++ = item; } }
static inline vector<string> split(const string& s, char delim) { vector<string> elems; split(s, delim, back_inserter(elems)); return elems; }

// Fast IO
static inline void fast() { ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }

// Loop shorthands
#define rep(i, high) for (int i = 0; i < high; i++)
#define repp(i, low, high) for (int i = low; i < high; i++)
#define repe(i, container) for (auto& i : container)
#define per(i, high) for (int i = high-1; i >= 0; i--)
#define perr(i, low, high) for (int i = high-1; i >= low; i--)

// Container shorthands
#define all(a) a.begin(),a.end()
#define reverse_all(a) a.rbegin(),a.rend()
#define contains(set, x) (set.find(x) != set.end())
#define sz(container) ((int)container.size())
#define firstElem(a) (*begin(a))
#define lastElem(a) (*prev(end(a)))

// Bounds check shorthand
#define within(a, b, c, d) (a >= 0 && a < b && c >= 0 && c < d)

// Math shorthands
#define ceildiv(x,y) ((x + y - 1) / y)
#define fract(a) (a-floor(a))


#define quit cout << endl; _Exit(0);


// Timing shorthands
#if 0
auto Start = chrono::high_resolution_clock::now();
#define elapsedmillis() (chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - Start).count())
#define rununtil(time) if (elapsedmillis() >= time) break;
#endif

// Random shorthands
#if 0
random_device rd;
mt19937 rng(rd());
#endif

// Debug shorthands
#ifdef _DEBUG
#define deb __debugbreak();
#define debassert(expr) if (!(expr)) deb;
#define debif(expr) if(expr) deb;
#else
#define deb ;
#define debassert(expr) ;
#define debif(expr) ;
#endif


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

int32_t main()
{
	fast();

	tread2(int, N, k);
	tread(string, startString);
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
			write(-1);
			quit;
		}
	}

	write(totalRotations);
	quit;
}
