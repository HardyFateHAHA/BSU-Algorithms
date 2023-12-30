#include <bits/stdc++.h>

using namespace std;
int rankk[500000];
int parent[500000];
void make_set (int v) {
	parent[v] = v;
	rankk[v] = 0;
}

int find_set (int v) {
	if (v == parent[v])
		return v;
	return parent[v] = find_set (parent[v]);
}

void union_sets (int a, int b) {
	a = find_set (a);
	b = find_set (b);
	if (a != b) {
		if (rankk[a] < rankk[b])
			swap (a, b);
		parent[b] = a;
		if (rankk[a] == rankk[b])
			++rankk[a];
	}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    int n , q;
    cin >> n >> q;
    int ans(n);
    for(int i = 1 ; i <= n ; i++)make_set(i);
    for(int i = 0 ; i < q ; i++){
        int f , s;
        cin >> f >> s;
        if(find_set(f) != find_set(s))ans--;
        union_sets(f , s);
        cout << ans << '\n';
    }
    return 0;
}