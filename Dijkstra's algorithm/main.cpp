#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long n, m, temp;
    cin >> n >> m;
    vector<map<long long, long long>> graph(n);

    for (long long i = 0; i < m; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        if (graph[a].count(b)) {
            graph[a][b] = min(graph[a][b], c);
            graph[b][a] = min(graph[b][a], c);
        } else {
            graph[a][b] = c;
            graph[b][a] = c;
        }
    }

    vector<long long> dist(n, INF);
    dist[0] = 0;
    set<pair<long long, long long>> f;
    f.insert({dist[0], 0});

    while (!f.empty()) {
        temp = f.begin()->second;
        f.erase(f.begin());
        for (auto &[v, c] : graph[temp]) {
            if (dist[v] > dist[temp] + c) {
                f.erase({dist[v], v});
                dist[v] = dist[temp] + c;
                f.insert({dist[v], v});
            }
        }
    }

    cout << dist[n - 1] << '\n';

    return 0;
}