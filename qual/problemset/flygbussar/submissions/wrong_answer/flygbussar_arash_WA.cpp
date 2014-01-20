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
typedef vector < LL > VI; // <-------------- Kör longlong överallt
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

// Arash Rouhani
// WA
// O(n^2)
// Kommentar: Jag tänkte lite fel när jag löste denna.
//
// Failande testcase:
//
// 2 10
// 1 19

int main(){
  mr2(int, n, k);
  VI arrivals(n);
  cin >> arrivals;
  sort(all(arrivals));

  if( n > 2000) {
    // Så att den kan bli WA enligt KATTIS definition
    cout << "123456" << endl;
    return 0;
  }
  

  // Först gör vi några precalculations
  VI where_we_end_up(n, n);
  foru(i, n) {
    foru(j, n) {
      // Otroligt wasteful loop, men varför krångla när vi har råd? :)
      if(arrivals[i] + 2*k <= arrivals[j]) {
        where_we_end_up[i] = j;
        break;
      }
    }
  }

  //                 (j, i]
#define COST_TO_DRIVE(j, i) \
  acc[i]-acc[j]-(j*(arrivals[i]-arrivals[j]))

  VI acc(n+0, 0);
  sfor(int, i, 1, n) {
    acc[i] = acc[i-1] + LL(i)*(arrivals[i]-arrivals[i-1]);
  }
  
  // dp[n+1][n+1] -- ["klockan"][Senaste skjutsade grupp minus ett]
  //
  // Så "klockan" i betyder alltså den tid då man hinner hämta arrivals[i].
  //
  // dp[0][0] == 0 -- I början så finns kan man säga att man är redo att hämta grupp 0, och den du senast skjutsade var grupp -1
  // SVAR: dp[n][n] -- Vi vill veta kostnaden då vi är redo att hämta grupp n+1 ("klockan oändliheten") och då grupp n har blivit skjutsade.
  //
  // Det var grunderna, formlerna för hur dp-värdena relaterar till
  // varandra framgår i koden.

  VVI dp(n+1, VI(n+1, LL(1)<<LL(10)));

  dp[0][0] = 0;

  foru(i, n) {
    foru(j, i + 1) {
      // Vi kan välja att inte göra en körning
      if( i < n ) {
        MIN(dp[i+1][j], dp[i][j]);
      }

      // Eller så gör vi en körning nu! Och vi hämtar alltså upp
      // alla till och med grupp i. Vi räknar kostnaden för grupperna j..i
      MIN(dp[where_we_end_up[i]][i+1], dp[i][j] + COST_TO_DRIVE(j, i) );
    }
  }
  // Ex1: dp[0][0] = 0   ===>  dp[1][0] = 0  ===>   dp[2][2] = 20 + 2  ===>  dp[3][3] = 30 + 2
  // Ex2: 
  // Ex3: dp[0][0] = 0   ===>  dp[1][0] = 0  ===>   dp[2][0] = 0 ===>  dp[3][0] = 0   ===> dp[4][3] = 6  ===> dp[5][5] = 10
  // 
  // Sista steget där var ej möjligt i min lösning, därav WA
  
  /* cout << where_we_end_up << endl; */
  /* cout << dp << endl; */

  cout << n*k + dp[n][n] << endl;
}
