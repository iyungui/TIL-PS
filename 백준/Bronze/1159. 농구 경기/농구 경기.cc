#include <bits/stdc++.h>

using namespace std;

int n;
string a, ret;
int cnt[26];
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a;
        cnt[a[0] - 'a']++;    // char -> int
    }
    for(int i = 0; i < 26; i++) {
        if(cnt[i] >= 5) {
            ret += i + 'a'; // int -> string
        }
    }
    if((int)ret.size()) cout << ret;
    else cout << "PREDAJA";
    return 0;
}
