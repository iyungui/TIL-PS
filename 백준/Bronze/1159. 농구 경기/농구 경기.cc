#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> v;
int cnt[26];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        string a;
        cin >> a;
        v.push_back(a);
    }
    for(string a : v) {
        int first = a[0] - 'a';
        cnt[first]++;
    }
    bool satisfied = false;
    for(int i = 0; i < 26; i++) {
        if(cnt[i] >= 5) {
            cout << (char)(i + 'a');
            satisfied = true;
        }
    }
    if(!satisfied) cout << "PREDAJA";
    return 0;
}