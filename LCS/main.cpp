#include <bits/stdc++.h>

using namespace std;
/*
⠄⠄⠄⠄⠄⢀⣀⣠⡿⠒⢄⢠⣴⣶⠶⢦⣤⣤⠚⠛⠳⣄
⠄⠄⠄⠄⠘⣯⠉⠉⠄⠄⢀⣼⡿⢠⣶⡂⢀⣿⠆⠄⠄⠙⠛⢶⡆
⠄⠄⠄⣀⡤⠜⣧⠄⠄⠄⠙⠛⠿⣦⡏⠉⡿⡇⠄⠄⢀⡆⠄⣼⡇
⠄⠄⢠⠇⠐⢿⣟⠃⠄⠳⣾⠁⠄⠈⠙⣆⠁⣿⡶⠾⠋⣀⣴⡟⠁⢦⡄
⢠⣾⠃⠄⠄⠄⠈⠻⣦⡀⠙⢷⡀⠄⠄⡼⢟⣩⡴⠶⠟⠛⠋⠁⠄⠸⡇
⢀⣾⢱⠄⠄⢠⡆⠄⠈⣿⡀⠈⠻⡄⠜⣶⠋⠄⠄⠄⠄⣷⡀⠄⠄⠄⠙⢦⣄
⣼⡇⡞⠄⠄⣾⡇⠄⠰⠿⣧⣄⠄⠹⡄⠇⠄⠄⠄⠄⣰⣿⣧⡴⠃⢀⡔⢂⣿⣆
⣿⣷⣿⠄⠶⠿⣿⣤⠄⠄⠄⠙⢷⣄⠹⡀⠄⠄⢀⣴⠿⠛⠉⠄⣠⡏⣰⡏⠁
⢻⣇⣉⡥⠤⠤⢤⣍⡻⢦⡀⠄⠈⢿⡄⡇⠄⡴⠋⠁⣀⣤⣤⣚⣛⢁⡿
⠈⠻⠋⠄⠄⠄⢷⣾⣽⣳⣝⢄⠄⠈⡇⠄⣨⢴⣚⣭⣽⡟⠄⠉⠉⠛⠁
⠄⠄⠄⠄⠄⠄⠄⠙⢿⣝⠛⠺⡂⠄⡣⡪⠒⠋⣉⣿⠟⠄⠄⠄⠄⠄⢀⠇
⠄⠄⠄⠄⠄⠄⠄⠄⠄⠙⠓⠄⠱⠜⢀⣀⡤⠖⠋⠁⠄⢀⣴⡠⠔⠚⠁⢰
⢠⡀⠄⠄⠄⠄⠄⠄⠄⠄⠘⣿⢠⣴⡶⠄⠄⠄⠄⠄⡔⠁⠄⣠⠔⠄⢠⡇
⠘⡝⠦⣀⣄⣀⠄⠄⠄⠄⠄⠙⣦⢻⡅⠄⠄⠄⠄⠟⣸⡶⠟⠓⠄⠰⢛⠞
⠄⠘⣄⠈⡁⠄⠉⠑⡚⠗⠢⣄⡈⠢⠻⣿⠄⠄⣆⡾⠗⠄⣀⣤⠴⠚⠁
⠄⠄⢸⡦⠄⠁⢒⠶⠚⠒⢚⣳⣿⣶⡀⠙⣧⠄⠟⣀⠴⠒⠚⠓
⠄⠄⠄⠑⢦⣄⣁⠄⠄⠄⠁⠄⣀⠄⠄⢀⡈⠳⣄
⠄⠄⠄⠄⠄⠈⠩⠽⠯⠶⠞⠋⠁⠄⠄⠄⣹⣦⡙⣧⡀
⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠉⠉⠛⢿⡌⣷⡀
⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠈⣿⡜⣇⡴
⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣄⣀⣿⡇⣿⡇
⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣿⣿⣿⣇⡿⠁
⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣽⣿⡟⠜
⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣠⠿⠋
*/
int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> B(n);
    for(int i = 0; i < n; ++i)cin >> A[i];
    for(int i = 0; i < n; ++i)cin >> B[i];
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            if(A[i - 1] == B[j - 1])dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    int k = dp[n][n];
    cout << k << endl;
    vector<int> indices_A, indices_B;
    int i = n, j = n;
    while(k > 0)
        if(A[i - 1] == B[j - 1]){
            indices_A.push_back(i - 1);
            indices_B.push_back(j - 1);
            i--;
            j--;
            k--;
        }else
             if(dp[i - 1][j] > dp[i][j - 1])i--;
                else j--;

    for(int x = indices_A.size() - 1; x >= 0; x--)cout << indices_A[x] << " ";
    cout << endl;
    for (int x = indices_B.size() - 1; x >= 0; x--)cout << indices_B[x] << " ";
    cout << endl;

    return 0;
}
/*
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢛⡛⠛⡛⠄⠝⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠋⣤⣦⠶⣷⣆⢀⡝⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢂⣽⠏⠄⠄⠄⠈⢻⣧⢨⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠡⣸⡏⠄⠄⠄⠄⠄⠄⢿⣇⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⡿⠿⠿⠿⠿⠟⠛⠛⠛⠛⠛⠟⠻⢋⢼⡟⠄⠄⠄⠄⠄⠄⠄⢸⣯⢈⢹⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⢰⣿⣿⣿⣿⣿⣿⣿⡿⠿⠛⠛⠉⠉⠉⠣⠄⠄⠄⠄⠄⠄⠄⣼⡧⠠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⡘⢿⣿⣿⣍⡩⠙⠁⠄⠄⠄⠄⠄⠄⠄⠄⠈⢂⠄⠄⠄⠄⣰⣿⣞⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣦⡙⡿⠋⠄⠄⠄⡀⠤⠄⠤⠄⠄⠄⠄⠄⠄⡆⠄⠄⣼⡟⠤⢈⠑⡙⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⡿⠡⠁⠄⠄⠄⡌⣰⣾⣿⣷⡄⢢⠄⠄⠄⠄⢱⢀⡾⣧⣭⣿⣆⢁⠐⡜⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⢧⠃⠄⠄⠄⠄⠇⢿⣿⣿⣿⡟⡸⠄⠄⠄⠄⠸⠿⡉⢹⣿⣿⡿⠸⠄⠐⠹⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⡿⠈⠄⠄⠄⠄⠄⠈⠢⢉⣛⡩⠔⠁⢀⠄⠄⠄⣠⡄⠄⠄⡑⠉⠐⠁⠄⠄⡇⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⡇⡇⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠑⢴⣚⣿⣿⣖⡖⠁⠄⠄⠄⠄⠄⢠⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⡇⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠈⡟⠛⠛⢿⠃⠄⠄⠄⠄⠄⠄⠘⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⡇⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠈⠒⠒⠄⠄⠄⠄⠄⠄⠄⠄⡆⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⡏⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢀⢰⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⢟⣡⠄⠄⠄⠄⠄⠄⠄⠂⢀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠒⢝⢿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⢸⣿⠄⠄⠄⠄⠄⠄⠄⠄⠄⠑⡀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠃⠄⠄⢢⢻⣿⣿⣿⣿⣿
⣿⣿⣿⢸⣿⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠰⢀⡀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠇⠄⠄⢀⢺⣿⣿⣿⣿⣿
⣿⣿⣿⢸⣿⡇⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠈⠑⠂⠠⢄⠄⠄⠄⠄⠄⢀⠔⠁⠄⠄⣠⢊⣾⣿⣿⣿⣿⣿
⣿⣿⣿⢸⣿⠃⠄⠄⠄⠄⠄⠄⠄⠈⠐⠒⠢⠤⠤⠤⠄⠄⠂⠄⠄⠄⠄⠣⠤⠒⠂⠁⠄⢜⢿⣿⣿⣿⣿⣿
⣿⣿⣿⢸⡟⠄⠄⠄⠄⠄⠄⠄⠄⠈⠁⠂⢄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠈⡜⣿⣿⣿⣿⣿
⣿⣿⣿⣌⢳⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢢⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣿⣿⣿⣿⣿
⣿⣿⣿⣿⡺⠆⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠈⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⡄⢿⣿⣿⣿⣿
⣿⣿⣿⡇⡇⣮⠢⣠⡶⢶⡀⠄⠄⠄⠄⠄⠠⠴⠄⡀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠈⠐⢝⢿⣿⣿
⣿⣿⣿⣧⢧⣉⣾⡋⠥⢺⣧⠄⣀⡀⠄⠄⠄⠄⠄⠈⠳⡀⠤⠤⠤⣀⣒⣬⣭⣤⣀⣀⣒⣂⡠⠤⠤⣸⣿⣿
⣿⣿⣿⣿⣿⣷⣬⣙⣛⠶⢟⣼⣷⣶⣶⣮⣭⣥⣖⣒⣒⣵⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⡿⣛⣛⣛⣛⡛⢟⣛⣛⣛⣛⡻⢛⣛⣛⣛⣛⢛⣛⠿⠿⠿⡿⢋⡆⡿⣛⣛⣛⣛⣛⣛⠿⢛⣛⣛⣛⠻⣿
⣿⡇⣿⣿⣯⣭⡿⠸⣧⣬⣿⣿⡇⢿⣿⣯⣭⢩⢸⣿⣷⠒⢶⡆⢿⣿⡆⣤⡀⣿⣿⢋⣥⢰⣮⣭⣿⣿⢇⣿
⣿⣷⣟⣥⣶⣶⣶⣷⣶⣶⣶⣶⣾⣶⣶⣶⣶⣾⣿⣶⣶⣿⣶⣾⣷⣶⣾⣿⣿⣶⣶⣿⣿⣷⣶⣶⣶⣶⣿⣿
*/