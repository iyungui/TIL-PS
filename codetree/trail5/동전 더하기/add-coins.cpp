#include <iostream>

using namespace std;

int n, k;
int coins[10];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    int cnt = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(k >= coins[i]) {
            cnt += (k / coins[i]);
            k %= coins[i];
        }
    }
    cout << cnt << '\n';
    return 0;
}
