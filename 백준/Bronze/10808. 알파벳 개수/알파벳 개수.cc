#include <bits/stdc++.h>

using namespace std;

int cnt[26];
string s;
int main() {
    cin >> s;
    for(int a : s) cnt[a - 'a']++;
    for(int i = 0; i < 26; i++) cout << cnt[i] << " ";
    return 0;
}
