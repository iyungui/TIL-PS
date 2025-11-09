#include<bits/stdc++.h>

using namespace std;

int T, n;
int arr[52][52];

int main() {
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cin >> n;
        memset(arr, 0, sizeof(arr));
        for(int i = 0; i < n; i++) {
            string temp;
            cin >> temp;
            for(int j = 0; j < n; j++) {
                arr[i][j] = (int)temp[j] - '0';
            }
        }
        int mid = n / 2;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            int j = (i <= mid) ? i : n - 1 - i;
            for(int k = 1; k <= j; k++) {
                sum += arr[i][mid - k];
                sum += arr[i][mid + k];
            }
            sum += arr[i][mid];
        }
        cout << "#" << t << " " << sum << '\n';
    }
    return 0;
}