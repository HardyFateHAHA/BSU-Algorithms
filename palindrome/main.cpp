#include <bits/stdc++.h>

using namespace std;

const int MAXN = 7005;
vector<vector<int>> dp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);

    string s;
    cin >> s;
    int n = s.size();
    dp.resize(n, vector<int>(n));
    for(int j = 1; j <= n; j++) {
        for(int i = 0; i + j <= n; i++) {
            if(j == 1)
                dp[i][i+j-1] = 1;
            else
                if(s[i] == s[i+j-1])
                    dp[i][i+j-1] = 2 + dp[i+1][i+j-2];
                else
                    dp[i][i+j-1] = max(dp[i+1][i+j-1], dp[i][i+j-2]);
        }
    }
    vector<int> is(s.size());
    for(int i = 0; i < s.size(); i++)
        is[i] = 1;

    int l = 0, r = s.size()-1;
    while(l <= r) {
        if(s[l] != s[r])
            if(dp[l][r-1] > dp[l+1][r])
                is[r] = 0, l--;
            else
                is[l] = 0, r++;
        l++, r--;
    }
    cout << dp[0][n-1] << endl;
    for(int i = 0; i < s.size(); i++)
        if(is[i])
            cout << s[i];

    return 0;
}
/*
*/
