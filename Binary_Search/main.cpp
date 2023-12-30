#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> mas(n);

    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }

    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
        long long x;
        cin >> x;
        if(n == 0){
            cout << "0 0 0" << endl;
            continue;
        }
        long long l = -1;
        long long r = n - 1;
        long long b = 0;

        while (l + 1 < r) {
            long long mid = (l + r) / 2;
            if (mas[mid] < x) {
                l = mid;
            } else {
                r = mid;
            }
        }

        if (mas[r] == x) {
            b = 1;
        }

        cout << b << " ";

        if (b == 0 && r == n - 1 && mas[r] < x) {
            r++;
        }

        cout << r << " ";
        l = -1;
        r = n;

        while (l + 1 < r) {
            long long mid = (l + r) / 2;
            if (mas[mid] <= x) {
                l = mid;
            } else {
                r = mid;
            }
        }

        cout << r << endl;
    }

    return 0;
}