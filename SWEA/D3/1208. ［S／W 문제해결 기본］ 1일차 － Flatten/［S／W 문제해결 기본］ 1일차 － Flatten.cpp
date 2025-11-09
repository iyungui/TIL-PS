#include<bits/stdc++.h>

using namespace std;

const int TC = 10;
const int n = 100;
int dump;
int a[n];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for(int t = 1; t <= TC; t++) {
        cin >> dump;
        for(int i = 0; i < n; i++) cin >> a[i];

        while(dump--) {
            // O(n)
            int maxIdx = 0;
            for(int i = 1; i < n; i++) {
                if(a[i] > a[maxIdx]) maxIdx = i;
            }

            // O(n)
            int minIdx = 0;
            for(int i = 1; i < n; i++) {
                if(a[i] < a[minIdx]) minIdx = i;
            }

            if(a[maxIdx] - a[minIdx] <= 1) break;
            
            a[maxIdx]--;
            a[minIdx]++;
        }

        int maxVal = *max_element(a, a + n);
        int minVal = *min_element(a, a + n);

        cout << "#" << t << " " << (maxVal - minVal) << '\n';
    }

    return 0;
}