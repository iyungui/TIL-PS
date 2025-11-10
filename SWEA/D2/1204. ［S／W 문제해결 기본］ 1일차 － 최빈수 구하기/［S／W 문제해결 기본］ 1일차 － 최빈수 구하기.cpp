#include<bits/stdc++.h>

using namespace std;

int T, t, temp;
int a[104];

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if(a.first == b.first) return a.second > b.second;
    return a.first > b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> T;
    while(T--) {
        cin >> t;
        memset(a, 0, sizeof(a));

        for(int i = 0; i < 1000; i++) {
            cin >> temp;
            a[temp]++;
        }
        
        vector<pair<int, int>> v;   // [빈도수, 점수]

        for(int i = 0; i <= 100; i++) {
            if(a[i] > 0) v.push_back({a[i], i});
        }

        // 빈도수 내림차순, 같으면 점수 내림차순
        sort(v.begin(), v.end(), cmp);

        cout << "#" << t << " " << v[0].second << '\n';
    }

    return 0;
}