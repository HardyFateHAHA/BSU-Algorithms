#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    int n;
    cin >> n;

    vector<int> a(n, -1);
    vector<int> num(n, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    int j = 0;
    for (int i = 0; i < n * n; i++) {
        int s;
        cin >> s;
        if (q.empty() || q.top().first > s) {
            a[j] = (j == 0 ? s / 2 : s - a[0]);
            q.emplace(s, j);
            j++;
        }

        int p = q.top().second;
        q.pop();
        num[p]++;
        if (num[p] == p * 2 + 1) {
            continue;
        }
        q.emplace(a[p] + a[num[p] / 2], p);
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << '\n';
    }
    return 0;
}