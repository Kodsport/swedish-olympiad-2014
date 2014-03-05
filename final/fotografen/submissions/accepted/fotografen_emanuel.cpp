/*
        Emanuel Gedin
        2013-12-19
*/
 
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
 
int main() {
        cin.sync_with_stdio(false);
        int n, k, ans = 0;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
                char c;
                cin >> c;
                if(c == 'U') a[i] = 0;
                else if(c == 'H') a[i] = 3;
                else if(c == 'N') a[i] = 2;
                else if(c == 'V') a[i] = 1;
                
        }
        queue<int> q;
        for(int i = 0; i <= n-k; i++) {
                while(!q.empty()) {
                        if(q.front() == i) q.pop();
                        else break;
                }
                int b = (a[i] - q.size())%4;
                ans += b;
                for(int j = 0; j < b; j++) q.push(i+k);
        }
        for(int i = n-k+1; i < n; i++) {
                while(!q.empty()) {
                        if(q.front() == i) q.pop();
                        else break;
                }
                int b = (a[i] - q.size())%4;
                if(b != 0) {
                        cout << -1 << endl;
                        return 0;
                }
        }
        cout << ans << endl;
        return 0;
}
