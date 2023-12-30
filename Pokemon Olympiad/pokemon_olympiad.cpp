#include <iostream>
#include <vector>
 
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int m, n;
    std::cin >> m >> n;
 
    std::vector<int> h(m);
    for(int i = 0; i < m; i++) {
        std::cin >> h[i];
    }
 
    std::vector<int> b(n);
    for(int j = 0; j < n; j++) {
        std::cin >> b[j];
    }
 
    std::vector<std::vector<int>> dp(m, std::vector<int> (n, 0)), p(m, std::vector<int>(n, -1));
    for(int j = 0; j < n; j++) {
        dp[0][j] = 1;
    }
 
    for(int i = 1; i < m; i++) {
        std::pair<int,int> s = {2e9 + 29, n};
 
        for(int j = 0; j < n; j++) {
            if (h[i] + b[j] > s.first) {
                dp[i][j] = 1;
                p[i][j] = s.second;
            }
            if (dp[i - 1][j]) {
                if (s.first > h[i - 1] + b[j]) {
                    s = {h[i - 1] + b[j], j};
                }
            }
        }
    }
 
    int i = m - 1;
    for (int j = n - 1; j > -1; j--) {
        if (dp[i][j]) {
            std::vector<int> a(m, 1e9);
 
            while (true) {
                a[i] = j + 1;
                j = p[i][j];
                i--;
 
                if (j < 0) {
                    break;
                }
            }
 
            for (const auto& i : a) {
                std::cout << i << " ";
            }
 
            return std::cout << "\n", 0;
        }
    }
 
    std::cout << "-1\n";
    return 0;
}