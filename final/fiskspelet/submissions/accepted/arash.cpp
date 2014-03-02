//Arash Rouhani
//#define _GLIBCXX_DEBUG
#define NDEBUG
#ifdef NDEBUG
  #define WHEN_DEBUG(x)
#else
  #define WHEN_DEBUG(x) x
#endif
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


struct Fish {
  LL x;
	int y, type;
	Fish() : x(-100), y(-100), type(-100) {}
	Fish(int x, int y, int t) : x(x), y(y), type(t) {}

  bool operator< (const Fish& other) const {
    if( x != other.x) return x < other.x;
    if( y != other.y) return y < other.y;
    return type < other.type;
  }
};


typedef vector <Fish> VF;
typedef vector <LL> VLL;

// starttime, approx 13:20
// got dp-version to compile at 13:47
// klara första testfall at 13:53
// whoups, glömde att fisken själv har höjd, men nu klarar jag dem 3 första testfallen, 14:00
//
// Ok, tar en paus för exjobb nu
//
// Ok, fortsätter nu kl 19:01
//
// Nu kompilerar min kompletta lösning, troligen buggar kvar at 19:26
// Klarar testdatat at 19:27
// Skapade två till testfall, klarar dem inte, at 19:40 (börjar debugga)
// Lol, klassiskt macrobug, skrev om, klarar testfallen at 19:52
//

int heights[4] = {3, 5, 9, -9999999};
int score[4] = {10, 20, -9999999, -9999999};

const int SMALL = 0;
const int MEDIUM = 1;
const int LARGE = 2;

VF killFishes(VF fishes, int h) {
  int n = sz(fishes);
  sort(all(fishes));
  reverse(all(fishes));

  VLL krSmall(h, 123456789123456789LL); // kr == killray
  VLL krMedium(h, 123456789123456789LL);

  VF ans; // We fill in as we sweep through

  foru(i, n) {
    Fish fish = fishes[i];
    switch(fish.type) {
      case SMALL:
        {
          bool survives = true;
          for(int y = fish.y-1 ; y <= fish.y+1; y++) {
            survives &= krSmall[y] > fish.x;
          }
          if(survives) {
            ans.push_back(fish);
          }
          break;
        }
      case MEDIUM:
        {
          LL leftestKr = 1234567890123456789LL;
          for(int y = fish.y-2 ; y <= fish.y+2; y++) {
            MIN(leftestKr, krMedium[y]);
          }

          bool survives = leftestKr > fish.x;
          if(survives) {
            ans.push_back(fish);
            for(int y = fish.y-2 ; y <= fish.y+2; y++) {
              MIN(krSmall[y], fish.x/2);
            }
          }
          else {
            // If dies
            LL xOfKiller = (leftestKr*3/2);
            assert(xOfKiller > fish.x);
            LL xWhereDied = (xOfKiller-fish.x)*3;
            for(int y = fish.y-2 ; y <= fish.y+2; y++) {
              MIN(krSmall[y], xWhereDied + (fish.x-xWhereDied)/2);
            }
          }
          break;
        }
      case LARGE:
        {
          ans.push_back(fish); // Always survives
          for(int y = fish.y-4 ; y <= fish.y+4; y++) {
            MIN(krSmall[y], fish.x/3);
            MIN(krMedium[y], fish.x*2/3);
          }
          break;
        }
    }
  }
  return ans;
}

VI updateSteps(VI values, LL steps) {
  int h = sz(values);
  VI newValues = values;
  foru(i, h) {
    for(int y = max(0LL, i - steps); y < min(LL(h), i + steps+1) ; y++) {
      MAX(newValues[i], values[y]);
    }
  }
  return newValues;
}

int dpStep(VF fishes, int h) {
  int n = sz(fishes);
  foru(i, n) {
    fishes[i].x /= fishes[i].type+1; // So x is now the time they'll arrive
  }
  sort(all(fishes));

  VI values(h);
  int i = 0;
  while(i < n) {
    int j = i;
    LL currx = fishes[i].x;
    while(j < n && currx == fishes[j].x) {
      int y0 = fishes[j].y;
      int fh = heights[fishes[j].type];
      for(int y = max(0, y0 - fh/2 - 3) ; y <= min(h-1, (y0 + fh/2 + 3)); y++) {
        values[y] += score[fishes[j].type];
      }
      j++;
    }
    LL diffx = (j < n ? fishes[j].x : 123456789123456789LL) - fishes[i].x;
    values = updateSteps(values, min(diffx, LL(h)));
    i = j;
  }

  return *max_element(all(values));
}

int main(){
  WHEN_DEBUG(cout << "Starting ..." << endl;)
  // First read input
  mr2(int, n, h);
  VF fishes;
  foru(i, n) {
    Fish f;
    char size;
    cin >> size >> f.x >> f.y;
    f.y--;
    f.type = 2*(size=='S') + 1*(size=='M'); // Swedish names, S == Stor
    fishes.push_back(f);
  }
  WHEN_DEBUG(cout << "Killing fishes ..." << endl;)
  fishes = killFishes(fishes, h);
  WHEN_DEBUG(cout << "dpstep ..." << endl;)
  int ans = dpStep(fishes, h);
  cout << ans << endl;
}
