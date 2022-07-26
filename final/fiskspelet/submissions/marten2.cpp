#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define MAXN 50005
#define MAXH 1060
#define INF 1000000000000000000LL
 
using namespace std;
 
struct Fish{
        bool dead;
        int sz;
        long long x, y;
        Fish* prev[MAXH];
        Fish* next[MAXH];
        Fish* eat[MAXH][2];
        bool killedBy[MAXH][2];
} fishes[MAXN];
 
bool comp(Fish* a, Fish* b){
        return a->x < b->x;
}
 
bool compArrive(Fish* a, Fish* b){
        return a->x/(a->sz+1) < b->x/(b->sz+1);
}
 
struct Event{
        Fish* hunter;
        Fish* prey;
        int y;
        long long time;
};
 
bool compEv(const Event* a, const Event* b){
        if(a->time == b->time){
                return a->hunter->sz < b->hunter->sz;
        }
        return a->time > b->time;
}
 
class Compare{
        Event* ev;
        public:
        bool operator() (const Event* lhs, const Event* rhs) const{
                return compEv(lhs, rhs);
        }
};
 
int n, h, height[3]={3, 5, 9}, score[3]={10, 20, -1000000000};
vector<Fish*> f[MAXH];
priority_queue<Event*, vector<Event*>, Compare> events;
vector<Fish*> coming;
int dp[2][MAXH];
int dpAdd[MAXH];
 
int main(){
        scanf("%d%d", &n, &h);
        for(int i=0; i < n; ++i){
                char t[2];
                scanf("%s%lld%lld", t, &fishes[i].x, &fishes[i].y);
                if(t[0] == 'S')
                        fishes[i].sz=2;
                else if(t[0] == 'M')
                        fishes[i].sz=1;
                else
                        fishes[i].sz=0;
                for(int j=fishes[i].y-height[fishes[i].sz]/2; j <= fishes[i].y+height[fishes[i].sz]/2; ++j){
                        f[j].push_back(&fishes[i]);
                }
        }
        for(int i=0; i < MAXH; ++i){
                sort(f[i].begin(), f[i].end(), comp);
                for(int k=1; k < f[i].size(); ++k){
                        f[i][k-1]->next[i] = f[i][k];
                        f[i][k]->prev[i] = f[i][k-1];
                        Event* ev = new Event();
                        ev->hunter = f[i][k];
                        ev->prey = f[i][k-1];
                        ev->y=i;
                        if(ev->hunter->sz <= ev->prey->sz)
                                ev->time=INF;
                        else{
                                ev->time=(ev->hunter->x-ev->prey->x)/(ev->hunter->sz-ev->prey->sz);
                                events.push(ev);
                        }
                }
                if(!f[i].empty()){
                        f[i][f[i].size()-1]->next[i]=NULL;
                        f[i][0]->prev[i]=NULL;
                }
        }
        while(!events.empty()){
                Event* ev = events.top();
#ifdef DEBUG
                printf("%lld %d %d\n", ev->time, ev->y, ev->prey->y);
#endif
                events.pop();
                if(ev->hunter->dead)
                        continue;
                long long x=ev->hunter->x-ev->time*(ev->hunter->sz+1);
                if(x < 0)
                        continue;
                if(ev->hunter->sz > ev->prey->sz && !ev->prey->dead){
                        ev->prey->dead=true;
#ifdef DEBUG
                        printf("   Died: %lld %d\n", ev->prey->x, ev->prey->y);
#endif
                        for(int y=ev->prey->y-height[ev->prey->sz]/2; y <= ev->prey->y+height[ev->prey->sz]/2; ++y){
                                if(ev->prey->prev[y] != NULL && ev->prey->next[y] != NULL){
                                        Event* newEvent = new Event();
                                        newEvent->hunter=ev->prey->next[y];
                                        newEvent->prey=ev->prey->prev[y];
                                        newEvent->y=y;
                                        newEvent->hunter->prev[y]=newEvent->prey;
                                        newEvent->prey->next[y]=newEvent->hunter;
                                        if(newEvent->hunter->sz <= newEvent->prey->sz)
                                                newEvent->time=INF;
                                        else{
                                                newEvent->time=(newEvent->hunter->x-newEvent->prey->x)/(newEvent->hunter->sz-newEvent->prey->sz);
                                                events.push(newEvent);
#ifdef DEBUG
                                                printf("   Added %lld, %d, %d\n", newEvent->time, newEvent->y, newEvent->prey->y);
#endif
                                        }
                                }
                        }
                }
        }
        for(int i=0; i < n; ++i){
                Fish* fish=&fishes[i];
                if(fish->dead)
                        continue;
                coming.push_back(fish);
        }
        sort(coming.begin(), coming.end(), compArrive);
        bool read=0, write=1;
        for(int i=0; i < MAXH; ++i)
                dp[write][i]=0;
        long long prevT=-1000;
        for(int i=0; i < coming.size(); ++i){
                Fish* fish=coming[i];
                write^=1;
                read^=1;
                for(int j=4; j <= h-3; ++j)
                        dpAdd[j]=0;
                for(int j=fish->y-height[fish->sz]/2-3; j <= fish->y+height[fish->sz]/2+3; ++j){
                        if(j < 0 || j >= MAXH)
                                continue;
                        dpAdd[j]=score[fish->sz];
                }
                long long curT=fish->x/(fish->sz+1);
        int best=-1000000000;
        int bestPos=0;
        long long B=4+curT-prevT;
        if(B > h-3)
            B=h-3;
        for(int k=4; k <= B; ++k)
            if(dp[read][k] >= best){
                best=dp[read][k];
                bestPos=k;
            }
                for(int k=4; k <= h-3; ++k){
            long long b=k+curT-prevT;
            if(b > h-3)
                b=h-3;
            if(dp[read][b] >= best){
                best=dp[read][b];
                bestPos=b;
            }
                        long long a=k-(curT-prevT);
                        if(a < 4)a=4;
                        if(a > bestPos){
                    best=-1000000000;
                for(int m=a; m <= b; ++m)
                    if(dp[read][m] > best){
                        best=dp[read][m];
                        bestPos=m;
                    }
                        }
                        dp[write][k]=best+dpAdd[k];
                }       
                prevT = curT;
        }
        int ans=-1000000000;
        for(int i=4; i <= h-3; ++i)
                ans=max(ans, dp[write][i]);
        printf("%d\n", ans);
}
