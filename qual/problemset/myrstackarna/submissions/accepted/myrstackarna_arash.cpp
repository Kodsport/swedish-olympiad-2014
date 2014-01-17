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
  assert(0 <= dir && dir < 8);
  return (dir + 2) % nDirs;
}

// Solution begins here:

int h, w;

II findStartSquare(VS karta) {
  foru(y, h) {
    foru(x, w) {
      if( karta[y][x] == 'U' ) {
        return II(y, x);
      }
    }
  }
}

VVI calcGravMap(VS karta, II start) {
  VVI gravmap(h, VI(w, -12345));
  queue<II> q;
  q.push(start);

#define HAVE_VISITID(y, x) (gravmap[y][x] != -12345)
  while(!q.empty()) {
    II ii = q.front(); q.pop();
    int y0 = ii.first;
    int x0 = ii.second;
    foru(dir, nDirs) {
      int y = y0 + yDirs[dir];
      int x = x0 + xDirs[dir];
      if(karta[y][x] == '#') continue;
      if(HAVE_VISITID(y,x)) continue;
      gravmap[y][x] = reverseDir(dir);
      q.push(II(y,x));
    }
  }
  return gravmap;
}

VII findAnts(VS karta) {
  VII ants;
  foru(y, h) {
    foru(x, w) {
      if( karta[y][x] == 'M' ) {
        ants.push_back(II(y, x));
      }
    }
  }
  return ants;
}

VII removeDuplicates(VII elems) {
  VII res;
  foru(i, sz(elems)) {
    bool is_unique = true;
    foru(j, sz(elems)) {
      if(i == j) continue;
      is_unique &= elems[i] != elems[j];
    }
    if(is_unique) {
      res.push_back(elems[i]);
    }
  }
  return res;
}


int main(){
  cin >> h >> w;
  VS karta(h);
  tr(karta, rad) {
    cin >> *rad;
  }

  II start = findStartSquare(karta);
  VVI gravmap = calcGravMap(karta, start);
  VII ants = findAnts(karta);
  int ans = 0;

#define DIR(ii) gravmap[ii.first][ii.second]
#define MOVE_ANT(ii) II((ii).first + yDirs[DIR((ii))], (ii).second + xDirs[DIR((ii))])
  while(!ants.empty()) {
    VII newAnts;
    tr(ants, ant) {
      newAnts.push_back(MOVE_ANT(*ant));
    }
    newAnts = removeDuplicates(newAnts);
    VII::iterator it = find(all(newAnts), start);
    if (it != newAnts.end()) {
      ans++;
      newAnts.erase(it); // It made it out alive! :)
    }
    ants = newAnts;
  }

  cout << ans << endl;
  return 0;
}
