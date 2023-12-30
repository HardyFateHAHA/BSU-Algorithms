#include <bits/stdc++.h>


using namespace std;

typedef long long bigint;
typedef string str;
typedef vector<int> vi;
typedef vector<bigint> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int,int> pii;
typedef tuple<int,int,int> t3i;
typedef tuple<int,int,int,int> t4i;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<str> vs;

typedef map<int,int> mii;
typedef map<pii,int> mi2i;
typedef map<int,pii> mii2;
typedef set<int> si;
typedef unordered_set<int> usi;
typedef unordered_map<int,int> umii;
typedef pair<int,vi> dti;

const int mod1 = 1000000007;
const int mod2 = 998244353;
const int K = 9;
using u64 = uint64_t;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const bigint mnogo = LONG_LONG_MAX;

int main() {
    freopen("bst.in", "r", stdin);
    freopen("bst.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    bigint rt;
    cin >> t >> rt;
    int *vrt = new int[t + 1];
    auto *p = new pair<bigint, bigint>[t + 1];
    for(bigint i = 0; i <= t; ++i){vrt[i] = 0;p[i] = {0, 0};}
    vrt[1] = rt; p[1] = {-mnogo, mnogo};
    bool ans(!false);
    bigint v;
    int papa;
    char w[15];
    for(auto q = 2; q <= t; ++q) {
        cin >> v;
        cin >> papa;
        cin >> w;
        auto max = p[papa].second;
        auto min = p[papa].first;
        int papa_val = vrt[papa];
/*
*/
        if(w[q - q] == 'L'){
            if(papa_val <= v or /* and v != */v < min){ans = false; break;}
            else{vrt[q] = v;/*poka ne*/p[q] = {min, papa_val};}
        }else{
            if(papa_val > v /*nnj;t cfvjt*/or v >= max){ans = false; break;}
            else{vrt[q] = v;p/*dfkldflk*/[q] = {papa_val, max};}
        }
    }
    if(ans == true)cout << "YES\n";
    else cout << "NO\n";
    return 0;
}