#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
        freopen("input.txt" , "r" , stdin);
        freopen("output.txt" , "w" , stdout);
    int n , m;
    cin >> n >> m;
    int a[n + 1][n + 1];
    for(int i = 1 ; i <= n ; i++)for(int j = 1 ; j <= n ; j++)a[i][j] = 0;
    int f , s;
    for(int t = 1 ; t <= m ; t++){cin >> f >> s;a[f][s] = 1; a[s][f] = 1;}
    for(int i = 1 ; i <= n ; i++){for(int j = 1 ; j <= n ; j++)cout << a[i][j] << ' '; cout << '\n';}
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