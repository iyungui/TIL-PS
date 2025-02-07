#include <bits/stdc++.h>
using namespace std;

string s;
int cnt[27];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    fill(&cnt[0], &cnt[0] + 27, -1);
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        if(cnt[(int)s[i] - 'a'] == -1) cnt[(int)s[i] - 'a'] = i;
    }
    for(int i = 0; i < 26; i++) {
        cout << cnt[i] << " ";
    }
    cout << '\n';
    return 0;
}