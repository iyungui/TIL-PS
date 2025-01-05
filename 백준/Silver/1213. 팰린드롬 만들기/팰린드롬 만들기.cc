#include <bits/stdc++.h>
using namespace std;

string a, ret;
int n, mid;
int cnt[26];

int main() {
    cin >> a;
    
    n = (int)a.size();
    
    // cnt
    for(char c : a) cnt[c - 'A']++;
    
    
    // isPelindrome
    int odd = 0;
    for(int i = 0; i < 26; i++) {
        if(cnt[i] % 2 == 1) {
            odd++;
            mid = i + 'A';
        }
    }
    
    if(odd >= 2) {
        cout << "I'm Sorry Hansoo";
        return 0;
    }
    
    // 여기까지 오면 펠린드롬 가능
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < cnt[i] / 2; j++) {
            ret += (char)(i + 'A');
        }
    }
    
    if(odd == 1) ret += mid;
    
    // 나머지 짝수 cnt (사전역순 배치)
    for(int i = 25; i >= 0; i--) {
        for(int j = 0; j < cnt[i] / 2; j++) {
            ret += (char)(i + 'A');
        }
    }
    
    cout << ret;
    
    return 0;
}
