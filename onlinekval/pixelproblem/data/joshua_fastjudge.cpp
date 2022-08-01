#include <bits/stdc++.h>
#include <filesystem>


using namespace std;

#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define p2 pair<ll, ll>
#define p3 vi
#define p4 vi
#define vp2 vector<p2>
#define vp3 vector<p3>
#define inf 2e9
#define linf 1e17

#define read(a) cin >> a
#define dread(type, a) type a; cin >> a
#define dread2(type, a, b) dread(type, a); dread(type, b)
#define write(a) cout << (a) << endl
#ifdef _DEBUG
#define deb __debugbreak();
#else
#define deb ;
#endif

#define readpush(type,a) {type temp; read(temp); a.push_back(temp);}
#define readinsert(type,a) {type temp; read(temp); a.insert(temp);}
#define setcontains(set, x) (set.find(x) != set.end())
#define stringcontains(str, x) (str.find(x) != string::npos)
#define all(a) begin(a),end(a)

#define rep(i, high) for (ll i = 0; i < high; i++)
#define repe(i, container) for (auto& i : container)
#define per(i, high) for (ll i = high; i >= 0; i--)

#define ceildiv(x,y) ((x + y - 1) / y)
#define fract(a) (a-floor(a))


inline void fast()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

inline float sqrt1(const float& n)
{
    static union { int i; float f; } u;
    u.i = 0x5F375A86 - (*(int*)&n >> 1);
    return (int(3) - n * u.f * u.f) * n * u.f * 0.5f;
}

vector<double> sqrtlookup(256 * 256 * 3, -1);

inline float coldist(tuple<int, int, int> a, tuple<int, int, int> b)
{
    int d1 = get<0>(a) - get<0>(b);
    int d2 = get<1>(a) - get<1>(b);
    int d3 = get<2>(a) - get<2>(b);
    int index = d1 * d1 + d2 * d2 + d3 * d3;
    if (sqrtlookup[index] != -1)
    {
        return sqrtlookup[index];
    }
    else
    {
        sqrtlookup[index] = sqrt1(index);
        return sqrtlookup[index];
    }
}

int solve(string filename, bool noheuristic = false)
{
    ifstream cin(filename);

    dread(int, n);
    vector<tuple<int, int, int>> cols(n * 3);
    rep(i, n * 3)
    {
        dread(int, r);
        dread(int, g);
        dread(int, b);
        cols[i] = { r,g,b };
    }


    vector<pair<float, int>> scores;

    for (int guessWidth = 20; guessWidth < 700; guessWidth++)
    {
        float score = 0;
        int j = 0;
        while (guessWidth * j + 1 + guessWidth - 1 < n)
        {
            rep(k, guessWidth)
            {
                score += coldist(cols[guessWidth * j + k], cols[(guessWidth * (j + 1)) + k]);
            }
            j++;
        }
        scores.push_back({ score, guessWidth });
    }

    sort(all(scores));


    // If the correct one is i, i-1,i-2,i-3 and i+1,i+2,i+3 are the most likely to be given falsely low scores

    vp2 centerscore(7);

    rep(i, 7) rep(j, 7) centerscore[i].first += abs(scores[i].second - scores[j].second);
    rep(i, 7) centerscore[i].second = i;
    sort(all(centerscore));

    vi candidates;
    rep(i, 7)
    {
        if (abs(scores[i].second - scores[centerscore[0].second].second) < 8)
        {
            candidates.push_back(scores[i].second);
        }
    }

    vector<pair<double, int>> linescore;
    auto getscore = [&](function<int(int)> getindex, function<int(int)> gettarget)
    {
        double score = 0;
        int j = 0;
        while (true)
        {
            int idx = getindex(j);
            int target = gettarget(idx);
            if (max(idx, target) >= n) break;
            score += coldist(cols[idx], cols[target]);
            j++;
        }
        return score;
    };
    rep(i, candidates.size())
    {
        int guessWidth = candidates[i];
        double score = 0;

        // -j-1 is right side line, +j is left side
        // distance from true=1
        score += getscore([&](int j) {return guessWidth * (j + 1) + j; },
            [&](int idx) {return idx + 1; });
        score += getscore([&](int j) {return guessWidth * (j + 1) - j - 1; },
            [&](int idx) {return idx - 1; });
        // distance from true=2
        score += getscore([&](int j) {return guessWidth * ((j + 2) / 2) - j - 1; },
            [&](int idx) {return idx - 2 + idx % 2; });
        score += getscore([&](int j) {return guessWidth * ((j + 2) / 2) + j; },
            [&](int idx) {return idx + 1 + idx % 2; });
        // distance from true=3
        score += getscore([&](int j) {return guessWidth * ((j + 3) / 3) - j - 1; },
            [&](int idx) {return idx - 3 + idx % 3; });
        score += getscore([&](int j) {return guessWidth * ((j + 3) / 3) + j; },
            [&](int idx) {return idx + 3 - idx % 3; });

        linescore.emplace_back(score, guessWidth);
    }
    sort(all(linescore));
    map<int, double> finalscores;
    rep(i, linescore.size())
    {
        finalscores[linescore[i].second] += pow(linescore[i].first / linescore[0].first, 1.7);
        rep(j, scores.size())
        {
            if (scores[j].second == linescore[i].second)
            {
                finalscores[linescore[i].second] += scores[j].first / scores[0].first;
                break;
            }
        }


    }
    linescore.resize(0);
    repe(score, finalscores)
    {
        linescore.emplace_back(score.second, score.first);
    }
    sort(all(linescore));
    return linescore[0].second;
}

std::string slurp(std::ifstream in) {
    std::ostringstream sstr;
    sstr << in.rdbuf();
    return sstr.str();
}

int main()
{
    fast();

#if 0
    //ifstream cin("C:\\Users\\Matis\\source\\repos\\Comp prog\\x64\\Debug\\in.txt");
    //ifstream cin("C:\\Users\\Matis\\desktop\\po-two\\swedish-olympiad-2014\\onlinekval\\pixelproblem\\data\\secret\\group15\\015-spinning_fast.in");
    ifstream cin("C:\\Users\\Matis\\desktop\\po-two\\swedish-olympiad-2014\\onlinekval\\pixelproblem\\data\\secret\\group9\\009-johan_conversation.in");
    //ifstream cin("C:\\Users\\Matis\\desktop\\po-two\\swedish-olympiad-2014\\onlinekval\\pixelproblem\\data\\secret\\group2\\002-another_hard_pattern.in");
#endif

    namespace fs = std::filesystem;

    const char* PATH = ".";

    //solve("C:\\Users\\Matis\\desktop\\po-two\\swedish-olympiad-2014\\onlinekval\\pixelproblem\\data\\secret\\group15\\015-spinning_fast.in");
    //solve("C:\\Users\\Matis\\desktop\\po-two\\swedish-olympiad-2014\\onlinekval\\pixelproblem\\data\\secret\\group015\\015-spinning_fast.in");
    //solve("C:\\Users\\Matis\\desktop\\po-two\\swedish-olympiad-2014\\onlinekval\\pixelproblem\\data\\secret\\group022\\022-tuppar.in");

    std::string path = "secret";
    for (const auto& entry : fs::directory_iterator("C:\\Users\\Matis\\desktop\\po-two\\swedish-olympiad-2014\\onlinekval\\pixelproblem\\data\\secret"))
    {
        if (!fs::is_directory(entry.path())) continue;

        auto dir = fs::directory_iterator(entry.path().string());

        fs::path ansfile;
        fs::path inputfile;

        for (const auto& entry : dir)
        {
            if (entry.path().extension() == ".in")
            {
                inputfile = entry.path();
            }
            if (entry.path().extension() == ".ans")
            {
                ansfile = entry.path();
            }
        }

        string name = inputfile.filename().string();
        string nameint = name.substr(0, 3);
        int n = stoi(nameint);
        /* if (n == 17)
         {
             cout << "haasfd";
         }*/
        int res = solve(inputfile.string());
        cout << "n: " << n << "\n";

        int judge_ans = stoi(slurp(ifstream(ansfile.string())));

        if (judge_ans != res)
        {
            cout << "error at " << inputfile.filename() << ": judge ans " << judge_ans << ", sol ans: " << res << ", no heuristic" << solve(inputfile.string()) << "\n";
        }

        //std::cout << entry.path() << std::endl;
    }

    return 0;
}