#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1000

map<int, int> mp;
map<int, int> mp_first;
int n, c, a[MAX_N];
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) return mp_first[a.first] < mp_first[b.first];
    return a.second > b.second;
}

int main() {
    cin >> n >> c;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        
        mp[a[i]]++;
        
        if(mp_first[a[i]] == 0) mp_first[a[i]] = i + 1;
    }
    
    for(auto it : mp) {
        v.push_back({it.first, it.second}); // first 가 a[i] 즉, 키가 되고 second가 빈도수
    }
    sort(v.begin(), v.end(), cmp);
    
    for(auto i : v) {
        for(int j = 0; j < i.second; j++) cout << i.first << " ";
    }
    return 0;
}
