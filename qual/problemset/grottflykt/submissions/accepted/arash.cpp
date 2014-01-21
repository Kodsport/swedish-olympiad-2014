//Arash Rouhani
#define _GLIBCXX_DEBUG
//#define NDEBUG
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
int yDirs[] = { 1, 0, -1, 0, 1, -1, -1, 1 };
int xDirs[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

int reverseDir(int dir) {
  assert(0 <= dir && dir < nDirs);
  return (dir&4) // Type of diagonal or not
       + (dir + 2)%4;
}

int w, h;
VS karta;
II find(char c) {
  foru(y, h) foru(x, w)
    if(karta[y][x] == c)
      return II(y,x);
}

struct State {
  II me, bear;
  bool operator< (const State& other) const {
    if( me == other.me) return bear < other.bear;
    return me < other.me;
  }
};

template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

State move_bear_one_step(State s) {
#define go(DIM)\
  if(s.me.DIM != s.bear.DIM) {\
    II cand = s.bear;\
    cand.DIM += sgn(s.me.DIM - s.bear.DIM);\
    if (karta[cand.first][cand.second] != '#') {\
      s.bear = cand;\
      return s;\
    }\
  }
  go(second);
  go(first);
  return s;
}

int main(){
  cin >> w >> h;
  karta = VS(h);
  cin >> karta;

  II goal = find( 'U');
  set<State> visited;
  map<State, int> cameDir;
  map<State, State> cameState;
  queue<State> q; // Could be stack to, no need for fastest
  State state0;
  state0.me = find( 'S');
  state0.bear = find( 'B');
  visited.insert(state0);
  cameDir[state0] = -1; // Should not happen!
  q.push(state0);

  State endState;
  endState.me = II(-1,-1);
  while(!q.empty() && endState.me == II(-1, -1)) {
    State s0 = q.front(); q.pop();
    foru(i, nDirs) {
      int y = s0.me.first + yDirs[i];
      int x = s0.me.second + xDirs[i];
      if(0 <= y && y < h && 0 <= x && x < w &&
         karta[y][x] != '#') {
        State s;
        s.me = II(y,x);
        s.bear = s0.bear;
        if(s.me == s.bear) {
          continue; // illegal move
        }
        s = move_bear_one_step(s);
        s = move_bear_one_step(s); // Move twice
        bool alive = s.me != s.bear;
        if(visited.count(s)) {
          continue;
        }
        visited.insert(s);
        cameDir[s] = i;
        cameState[s] = s0;
        if(s.me == goal) {
          endState = s;
          break;
        }
        if(alive) {
          q.push(s);
        }
      }
    }
  }
  assert(endState.me == goal);
  cout << endState.me << endState.bear <<endl;
  VI moves;
  State s = endState;
  while(cameDir[s] != -1) {
    moves.push_back(cameDir[s]);
    s = cameState[s];
  }
  reverse(all(moves));
  tr(moves, it) {
    char mn[4] = { 'N', 'H', 'U', 'V' };
    cout << mn[*it];
  }
  cout << endl;
}

