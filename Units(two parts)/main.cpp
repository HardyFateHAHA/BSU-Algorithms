#include <bits/stdc++.h>

long long C(long long n, long long k);
long long Evklid(long long a, long long m);
using namespace std;
int main() {
    long long n(0) , k(0);
    cin >> n >> k;
    if (k == 0){
        cout << 1 << endl;
        return 0;
    }
    cout << C(n, k) << endl;
    return 0;
}
long long C(long long n, long long k) {
    long long result = 1;
    if (k == 1 || k == n - 1)return n;
    long long ans1 = 1;
    long long ans3 = 1;

    for (long long i = 1; i <= k; i++) {
        ans1 = (ans1 * ((n - i + 1) % 1000000007)) % 1000000007;
        ans3 = (ans3 * i) % 1000000007;
    }
    long long ans2 = Evklid(ans3, 1000000007);
    result = (ans1 * ans2) % 1000000007;
    return result;
}

long long Evklid(long long a, long long m) {
    long long m0 = m , x0 = 0, x1 = 1;
    while(a > 1){
        long long q(a / m) , t(m);
        m = a % m;  a = t; t = x0;
        x0 = x1 - q * x0; x1 = t;
    }
    if (x1 < 0)x1 += m0;
    return x1;
}