#include <bits/stdc++.h>

using namespace std;

int main() {
       freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);

    int n ;
    cin >> n;
    int a[n + 1];
    bool flag = true;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        if(i == 1)continue;
        int k = (i - i % 2)/2;
        if(a[i] < a[k])flag = false;
    }
    if(flag)cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
