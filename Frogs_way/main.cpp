#include <bits/stdc++.h>

using namespace std;


int main()
{
//    freopen("input.txt" , "r" , stdin);
//    freopen("output.txt" , "w" , stdout);
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int a[n + 1] , s[n + 1]  , ans , mx(-1);
    for(int i = 0 ; i < n ; ++i){
        cin >> a[i];
        if(i == 0){
            s[i] = a[i];
            continue;
        }
        if(i == 1){
            s[i] = -1;
            continue;
        }
        s[i] = a[i];
        if(s[i - 2] != -1 and s[i - 3] != -1){
            s[i] = max(s[i - 2] + a[i] , s[i - 3] + a[i]);

        }else{
            if(s[i - 2] != -1)s[i] = s[i - 2] + a[i];
            else if(s[i - 3] != -1)s[i] = s[i - 3] + a[i];
            else{
                cout << -1 << endl;
                return 0;
            }

        }
    }
    cout << s[n - 1] << endl;

    if(s[n - 1] != -1){
         int ans[n];
         for(int i = 0 ; i < n ; i++)ans[i] = -1;
         ans[0] = n;
         int k(1);
         for(int i = n - 1 ; i > 3 ; i--){
            if(s[i - 2] > s[i - 3])ans[k] = i - 1 , k++ , i--;
            else ans[k] = i - 2, k++ , i -= 2;
         }
         if(n != 1)ans[k] = 1;
         for(int i = n - 1 ; i >= 0 ; i--){
             if(ans[i] == -1)continue;
             /*if(ans[i] != ans[i + 1])*/cout << ans[i] << " ";
         }
         if(n != 0)cout << endl;
    }

    return 0;
}