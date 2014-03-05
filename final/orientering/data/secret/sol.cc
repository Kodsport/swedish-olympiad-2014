//Arash Rouhani
//#define _GLIBCXX_DEBUG
#define NDEBUG
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>
#include <fstream>
#include <numeric>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <bitset>
#include <assert.h>

using namespace std;

typedef long long LL;
typedef pair < int, int > II;
typedef pair < int, II > I_II;
typedef vector < int > VI;
typedef vector < II > VII;
typedef vector < VI > VVI;
typedef vector < VII > VVII;
typedef vector < VVI > VVVI;
typedef vector < string > VS;
typedef vector < VS > VVS;
typedef vector < char > VC;
typedef vector < VC > VVC;
typedef stringstream SS;
typedef set < int > SI;
typedef set < SI > SSI;
typedef vector < SI > VSI;

#define sz(c) (int((c).size()))
#define all(c) (c).begin(), (c).end()
#define tr(c, it) for(typeof((c).begin()) it = (c).begin(); it!=(c).end(); it++)
#define sfor(type, e, start, stop) for(type e=start; e<stop; e++)
#define foru(var, stop) sfor(int, var, 0, stop)
#define sford(type, e, start, stop) for(type e=start; e>=stop; e--)
#define ford(var, start) sford(int, var, start, 0)
#define mp make_pair
#define error(msg) {cout << msg << endl; throw;}
#define mr(type, v1) \
  type v1; \
  cin >> v1;
#define mr2(type, v1, v2) \
  type v1, v2; \
  cin >> v1 >> v2;
#define mr3(type, v1, v2, v3) \
  type v1, v2, v3; \
  cin >> v1 >> v2 >> v3;
#define mr4(type, v1, v2, v3, v4) \
  type v1, v2, v3, v4; \
  cin >> v1 >> v2 >> v3 >> v4;
#define mr5(type, v1, v2, v3, v4, v5) \
  type v1, v2, v3, v4, v5; \
  cin >> v1 >> v2 >> v3 >> v4 >> v5;
#define MAX(l, r) l = max((l),(r))
#define MIN(l, r) l = min((l),(r))

template <class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
template <class T> string vectorToString(vector < T > v, string seperator = " "){
  ostringstream oss;
  tr(v, e) {
    oss << *e << seperator;
  }
  oss.flush();
  return oss.str();
}
template <class T1, class T2> std::ostream& operator << ( std::ostream& out,
                        const std::pair< T1, T2 >& rhs )
{
    out << "(" << rhs.first << ", " << rhs.second << ")";
    return out;
}

template <class T> std::ostream& operator << ( std::ostream& out,
                        const vector< T >& rhs )
{
    tr(rhs, it){
      out << *it << " ";
    }
    return out;
}

template <class T> std::istream& operator >> ( std::istream& in,
                        vector< T >& rhs )
{
    
    if(false /* sz(rhs) == 0 */){
      // Do getline and assume that's our elements
      string s;
      getline(in, s);
      if(s == "\n" || s == "") getline(in, s);
      stringstream sin(s);
      T temp;
      while(sin >> temp) rhs.push_back(temp); 
    } else {
      // read fixed number of elements
      tr(rhs, it) in >> *it;
    }
    return in;
}

template <class InIt> string rangeToString(InIt begin, InIt end, string seperator = " "){
  ostringstream oss;
  for(InIt it = begin; it != end; it++)
    oss << *it << seperator;
  oss.flush();
  return oss.str();
}

int nDirs = 4; // Change to 8 if needed
int yDirs[] = { 1, 0, -1, 0};
int xDirs[] = { 0, 1, 0, -1};

struct State {
  int y, x, dir;
  State() : x(-100), y(-100), dir(-100) {}
  State(int y, int x, int t) : x(x), y(y), dir(t) {}

  bool operator< (const State& other) const {
    if( x != other.x) return x < other.x;
    if( y != other.y) return y < other.y;
    return dir < other.dir;
  }
};

struct StateC {
  State s;
  int c;
  StateC (State s, int c) : s(s), c(c) {}
};

int main(){
  VI to_dir(255, -1);
  to_dir['v'] = 0;
  to_dir['>'] = 1;
  to_dir['^'] = 2;
  to_dir['<'] = 3;

  mr4(int, N, M, R, C);
  VS karta(N);
  tr(karta, it) cin >> *it;

  deque<StateC> dq;
  set<State> visited;
  const State state0(0,0,1); // 1 == höger
  dq.push_back(StateC(state0,0));
  while(!dq.empty()) {
    StateC sc = dq.front(); dq.pop_front();
    const State s0 = sc.s;
    /* cout << I_II(s0.dir, II(s0.y, s0.x)) << endl; */
    if(!visited.count(s0)) {
      visited.insert(s0);
      bool did_win = s0.y == (R-1) && s0.x == (C-1);
      if (did_win) {
        cout << sc.c << endl;
        return 0;
      }
      int dir = to_dir[karta[s0.y][s0.x]];
      {
        State s(s0.y + yDirs[s0.dir], s0.x + xDirs[s0.dir], s0.dir);
        if(0 <= s.y && s.y < N &&
            0 <= s.x && s.x < M){
          if(dir >= 0 && dir != s0.dir) {
            // don't follow arrow, go ahead
            dq.push_back(StateC(s, sc.c + 1));
          }
          else {
            // there is no arrow, keep going
            dq.push_front(StateC(s, sc.c));
          }
        }
      }
      if (dir >= 0) {
        // follow the arrow, change direction
        State s(s0.y, s0.x, dir);
        dq.push_front(StateC(s, sc.c));
      }
    }
  }
  cout << -1 << endl;
  assert(false);
  return 1;
}
