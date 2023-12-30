#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
        freopen("input.txt" , "r" , stdin);
        freopen("output.txt" , "w" , stdout);
    int n , f , s;
    cin >> n;
    map<int , int> m;
    for(int i = 0 ; i < n - 1 ; i++){
        cin >> f >> s;
        m.insert({s , f});
    }
    for(int i = 1 ; i <= n ; i++)cout << m[i] << " ";
    cout << '\n';
    return 0;
}
/*
4 6 6
1 2
2 3
3 4
4 1
3 1
4 2
1
6
2
5
4
3
0
0
0
0
0
0
 3
0 kol = 4
0 3
1 kol = 3
00 3
2 kol = 2
000 2
0001 1
00011 1
111000
*/