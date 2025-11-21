#include<bits/stdc++.h>
using namespace std;

int n, c, num;
vector<int> v;
map<int, int> mp, mp2;

bool cmp(int a, int b) {
    if(mp[a] == mp[b]) return mp2[a] < mp2[b];
    return mp[a] > mp[b];
}

int main() {
    cin >> n >> c;
    for(int i = 0; i < n; i++) {
        cin >> num;
        mp[num]++;
        if(mp2[num] == 0) mp2[num] = i + 1;
        v.push_back(num);
    }
    sort(v.begin(), v.end(), cmp);
    for(int i : v) cout << i << " ";
    return 0;
}