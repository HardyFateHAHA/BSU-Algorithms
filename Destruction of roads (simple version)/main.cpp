#include <bits/stdc++.h>

using namespace std;
int rankk[100000];
int parent[100000];

void make_set(int v) {
    parent[v] = v;
    rankk[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])return v;
    return parent[v] = find_set(parent[v]);
}

bool union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rankk[a] < rankk[b])
            swap(a, b);
        parent[b] = a;
        if (rankk[a] == rankk[b])
            ++rankk[a];
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m, q;
    cin >> n >> m >> q;
    int f[m], s[m], r[q], kol = n;
    bool t[m], flag = false;
    for (int i = 1; i <= n; i++)
        make_set(i);
    for (int i = 0; i < m; i++) {
        cin >> f[i] >> s[i];
        t[i] = true;
    }
    for (int i = 0; i < q; i++) {
        cin >> r[i];
        t[r[i] - 1] = false;
    }
    for (int i = 0; i < m; i++)if (t[i])if (union_sets(f[i], s[i]))kol--;
    string ans = "";
    for (int i = q - 1; i >= 0; i--) {
        if (flag) {
            ans.push_back('1');
            continue;
        }
        if (kol == 1) {
            flag = true;
            ans.push_back('1');
            continue;
        } else ans.push_back('0');
        if (union_sets(f[r[i] - 1], s[r[i] - 1]))kol--;
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
    cout << '\n';
    return 0;
}