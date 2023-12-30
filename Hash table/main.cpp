#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    int N , M , C;
    cin >> M >> C >> N;
    int a , q = 0;
    unordered_set <int> us;
    vector<int> v;
    vector<int> s(M);
    while(q < N){
        cin >> a;
        if(us.count(a) < 1)v.push_back(a) , us.insert(a);
        q++;
    } q = 0;
    while(q < M)s[q] = -1 , q++; q = 0;
    vector<int> f;
    while(q < v.size()){
        int temp = v[q] / M;
        f.push_back(temp);
        v[q] %= M;
        q++;
    } q = 0;
    int F(0);
    while(q < v.size()){
        F = 0;
        int  j = 0;
        while(F != 1){
              int pos = (v[q] + C * j) % M;
              if (s[pos] != -1)j++;
              else s[pos] = v[q] + M * f[q] , F = 1;
        }
        q++;
    }
    q = 0;
    while(q < s.size()){
        cout << s[q] << " ";
        q++;
    }
    cout << '\n';
    return 0;
}