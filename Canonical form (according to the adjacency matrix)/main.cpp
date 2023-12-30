#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
        freopen("input.txt" , "r" , stdin);
        freopen("output.txt" , "w" , stdout);
    int n , a;
    cin >> n;
    vector<int> ans(n + 1, 0);
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            cin >> a;
            if(a == 1)ans[j] = i;
        }
    }
    for(int i = 1 ; i <= n ; i++)cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}