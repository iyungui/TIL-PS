#include <bits/stdc++.h>

using namespace std;

int countings[126];
string s;
int main() {
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        countings[(int)s[i]]++;
    }
    for(int i = 97; i < 97 + 26; i++) {
        cout << countings[i] << " ";
    }
    return 0;
}
