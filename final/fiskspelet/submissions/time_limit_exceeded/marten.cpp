#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define MAXN 50005
#define MAXH 1005
 
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
vector<Fish*> f[MAXH][3];
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
                        f[j][fishes[i].sz].push_back(&fishes[i]);
                }
        }
        for(int i=0; i < MAXH; ++i)
                for(int j=0; j < 3; ++j){
                        sort(f[i][j].begin(), f[i][j].end(), comp);
                        for(int k=1; k < f[i][j].size(); ++k){
                                f[i][j][k-1]->next[i] = f[i][j][k];
                                f[i][j][k]->prev[i] = f[i][j][k-1];
                        }
                        if(!f[i][j].empty()){
                                f[i][j][f[i][j].size()-1]->next[i]=NULL;
                                f[i][j][0]->prev[i]=NULL;
                        }
                }
        for(int i=0; i < MAXH; ++i)
                for(int j=0; j < 3; ++j)
                        for(int k=j+1; k < 3; ++k){
                                int pos1=0, pos2=0;
                                while(pos2 < f[i][k].size()){
                                        while(pos1 < f[i][j].size() && f[i][j][pos1]->x < f[i][k][pos2]->x)
                                                ++pos1;
                                        if(pos1){
                                                f[i][k][pos2]->eat[i][j] = f[i][j][pos1-1];
                                                Event* ev = new Event();
                                                ev->hunter = f[i][k][pos2];
                                                ev->prey = f[i][j][pos1-1];
                                                ev->y=i;
                                                ev->time=(ev->hunter->x-ev->prey->x)/(ev->hunter->sz-ev->prey->sz);
                                                events.push(ev);
                                        }
                                        ++pos2;
                                }
                        }
        while(!events.empty()){
                Event* ev = events.top();
                //printf("%d %d %d\n", ev->time, ev->y, ev->prey->y);
                events.pop();
                if(ev->hunter->dead)
                        continue;
                if(ev->prey->killedBy[ev->y][ev->hunter->sz-1])
                        continue;
                long long x=ev->hunter->x-ev->time*(ev->hunter->sz+1);
                ev->prey->killedBy[ev->y][ev->hunter->sz-1]=true;
                if(x < 0)
                        continue;
                //if(!ev->prey->dead)
                        //printf("%d %d\n", ev->prey->x, ev->prey->y);
                ev->prey->dead=true;
                if(ev->prey->sz == 1)
                        for(int i=ev->prey->y-2; i <= ev->prey->y+2; ++i){
                                if(ev->prey->eat[i][2] != NULL && ev->prey->next[i] != NULL){
                                        Event* newEvent = new Event();
                                        newEvent->hunter=ev->prey->next[i];
                                        newEvent->prey=ev->prey->eat[i][2];
                                        newEvent->y=ev->y;
                                        newEvent->time=(newEvent->hunter->x-newEvent->prey->x)/(newEvent->hunter->sz-newEvent->prey->sz);
                                        events.push(newEvent);
                                        //printf("Added %d, %d, %d", newEvent->time, newEvent->y, newEvent->prey->y);
 
                                }
                        }
                if(ev->prey->prev[ev->y] != NULL){
                        Event* newEvent = new Event();
                        newEvent->hunter=ev->hunter;
                        newEvent->prey=ev->prey->prev[ev->y];
                        newEvent->y=ev->y;
                        newEvent->time=(newEvent->hunter->x-newEvent->prey->x)/(newEvent->hunter->sz-newEvent->prey->sz);
                        events.push(newEvent);
                        //printf("Added %d, %d, %d\n", newEvent->time, newEvent->y, newEvent->prey->y);
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
                for(int k=4; k <= h-3; ++k){
                        long long a=k-(curT-prevT);
                        if(a < 4)a=4;
                        long long b=k+(curT-prevT);
                        if(b > h-3)b=h-3;
                        dp[write][k]=-1000000000;
                        for(int m=a; m <= b; ++m)
                                dp[write][k]=max(dp[write][k], dp[read][m]+dpAdd[k]);
                }       
                prevT = curT;
        }
        int ans=-1000000000;
        for(int i=4; i <= h-3; ++i)
                ans=max(ans, dp[write][i]);
        printf("%d\n", ans);
}
