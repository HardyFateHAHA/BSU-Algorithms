#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 0);
    vector<int> tails(n, 0);
    int len = 1;

    dp[0] = nums[0];
    tails[0] = nums[0];

    for (int i = 1; i < n; i++) {
        if (nums[i] < tails[0]) {
            tails[0] = nums[i];
        } else if (nums[i] > tails[len - 1]) {
            tails[len] = nums[i];
            len++;
        } else {
            int pos = lower_bound(tails.begin(), tails.begin() + len, nums[i]) - tails.begin();
            tails[pos] = nums[i];
        }
    }

    return len;
}

int main() {
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int result = longestIncreasingSubsequence(A);
    cout << result << endl;

    return 0;
}