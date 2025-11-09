#include<bits/stdc++.h>

using namespace std;

const int TC = 10;
const int n = 100;
int dump, a;
int low = 101, high;
int cnt[n + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for(int t = 1; t <= TC; t++) {
        cin >> dump;
        low = 101; high = 0;
        memset(cnt, 0, sizeof(cnt));

        for(int i = 0; i < n; i++) {
            cin >> a;
            cnt[a]++;
            low = min(low, a);
            high = max(high, a);
        }

        while(dump-- && high - low > 1) {
            cnt[high]--;
            cnt[high - 1]++;
        
            cnt[low]--;
            cnt[low + 1]++;

            while(cnt[low] == 0) low++;
            while(cnt[high] == 0) high--;
        }
        cout << "#" << t << " " << high - low << '\n';
    }

    return 0;
}