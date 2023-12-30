#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    long long a , sum(0);
    set <int> s;
    while(cin >> a){
        s.insert(a);
    }
    for(auto i : s){
        sum += i;
    }
    cout << sum  << endl;
    return 0;
}