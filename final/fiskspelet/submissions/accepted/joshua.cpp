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


struct fish
{
    ll x, y, h, t;
    fish(ll x, ll y, ll h) : x(x), y(y), h(h), t(-1) {}
    fish() : x(-1), y(-1), h(-1), t(-1) {}
};
bool comparefish(fish& a, fish& b) { return a.t < b.t; }
bool comparefish2(fish& a, fish& b) { return a.x > b.x; }
typedef vector<fish> vf;


vf killfish(vf& fishes, int h)
{
    // You can only be killed by fishes behind you. Guaranteed no initial overlap thankfully
    sort(all(fishes), comparefish2);

    vf ret;

    // The interval which are fish to the right are killed
    vector<ll> fishkillersmall(h, ll(1e18));
    vector<ll> fishkillermedium(h, ll(1e18));

    repe(fishe, fishes)
    {
        ll leftestkill = ll(1e18);
        if (fishe.h == 3)
        {
            bool survives = true;
            for (int i = fishe.y; i < fishe.y + 3; i++)
            {
                survives &= fishkillersmall[i] > fishe.x;
            }

            // Units of time until eaten

            if (!survives)
            {
                // Dies
            }
            else
            {
                ret.emplace_back(fishe);
            }
        }
        else if (fishe.h == 5)
        {
            for (int i = fishe.y; i < fishe.y + 5; i++)
            {
                leftestkill = min(leftestkill, fishkillermedium[i]);
            }

            // Units of time until eaten
            bool survives = leftestkill > fishe.x;

            if (!survives)
            {
                // Dies
                ll xOfKiller = (leftestkill * 3 / 2);
                ll stepsTakenByMediumFish = (xOfKiller - fishe.x) * 2;
                ll xWhereDied = fishe.x - stepsTakenByMediumFish;

                for (int i = fishe.y; i < min((ll)h, fishe.y + 5); i++)
                {
                    fishkillersmall[i] = min(fishkillersmall[i], (xWhereDied + (fishe.x - xWhereDied) / 2) + 1);
                }
            }
            else
            {
                ret.emplace_back(fishe);
                for (int i = fishe.y; i < min((ll)h, fishe.y + 5); i++)
                {
                    fishkillersmall[i] = min(fishkillersmall[i], fishe.x / 2);
                }
            }
        }
        else if (fishe.h == 9)
        {
            ret.emplace_back(fishe);
            for (int i = fishe.y; i < min((ll)h, fishe.y + 9); i++)
            {
                fishkillermedium[i] = min(fishkillermedium[i], fishe.x * 2 / 3);
                fishkillersmall[i] = min(fishkillersmall[i], fishe.x / 3);
            }
        }
    }

    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, gameh;
    cin >> n >> gameh;

    vf fishes(n);

    rep(i, n)
    {
        char type;
        ll x,y;
        cin >> type >> x >> y;
        y--;

        int h;
        if (type == 'L') h = 3;
        if (type == 'M') h = 5;
        if (type == 'S') h = 9;

        y -= h / 2;

        fishes[i] = { x, y, h };
    }

    // Spaces for bottom of fish
    vi dp(gameh - 6, 0);
    vi newdp(gameh - 6, 0);

    // Max n collisions
    vector<fish> events = killfish(fishes, gameh);

    repe(f, events)
    {
        int speed = 0;
        if (f.h == 3) speed = 1;
        if (f.h == 5) speed = 2;
        if (f.h == 9) speed = 3;

        f.t = f.x / speed;
    }
    sort(all(events), comparefish);

    // Each event can max take O(hlog(h)) time

    ll time = 0;
    rep(ev, events.size())
    {
        ll t = events[ev].t;
        int h = events[ev].h;
        int y = events[ev].y;

        ll dt = t - time;
        time = t;

        int updateD = min(dt, (ll)dp.size());
        int l = 2 * updateD;
        deque<int> q;
        rep(i, gameh - 6 + updateD)
        {
            while (q.size() && i - q.front() > l) q.pop_front();

            while (q.size() && i < dp.size() && dp[q.back()] < dp[i]) q.pop_back();

            q.push_back(i);

            if (i >= updateD) newdp[i - updateD] = dp[q.front()];
        }

        // Update fishe score
        int score;
        if (h == 3) score = 10;
        if (h == 5) score = 20;
        if (h == 9) score = -int(1e9);

        int lo = max(0, y - 6);
        int hi = min(gameh - 6, y + h);

        for (int i = lo; i < hi; i++)
        {
            newdp[i] += score;
        }

        // Swap dp tables
        dp.swap(newdp);
        rep(i, newdp.size()) newdp[i] = 0;
    }

    cout << *max_element(all(dp));

    return 0;
}
