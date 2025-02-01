#include <bits/stdc++.h>
using namespace std;

int n, k, words[51], ret;
string s;

// 현재 배운 글자들로 읽을 수 있는 단어 수 반환
int count_readable(int mask) {
    int cnt = 0;
    for(int word : words) {
        if(word && (word & mask) == word) cnt++;
    }
    return cnt;
}

// index: 현재 알파벳, selected: 현재까지 선택한 알파벳 수
// base_mask: antic + 추가로 선택한 알파벳들의 비트마스크
void go(int index, int selected, int need_to_select, int base_mask) {
    // k-5개를 다 선택했으면
    if(selected == need_to_select) {
        ret = max(ret, count_readable(base_mask));
        return;
    }
    
    // 남은 알파벳 수가 필요한 수보다 적으면 불가능
    if(26 - index < need_to_select - selected) return;
    
    // 현재 알파벳이 antic이면 건너뛰기
    if(index == 'a'-'a' || index == 'n'-'a' || index == 't'-'a' ||
       index == 'i'-'a' || index == 'c'-'a') {
        go(index + 1, selected, need_to_select, base_mask);
        return;
    }
    
    // 1. 현재 알파벳 선택
    go(index + 1, selected + 1, need_to_select, base_mask | (1 << index));
    // 2. 현재 알파벳 선택하지 않음
    go(index + 1, selected, need_to_select, base_mask);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> k;
    
    // k가 5보다 작으면 antic도 못 배우므로 0 출력
    if(k < 5) {
        cout << 0 << '\n';
        return 0;
    }
    
    // 단어들을 비트마스크로 변환
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(char c : s) {
            words[i] |= (1 << (c - 'a'));
        }
    }
    
    // 기본 글자(antic) 마스크 생성
    int base_mask = 0;
    base_mask |= (1 << ('a' - 'a'));
    base_mask |= (1 << ('n' - 'a'));
    base_mask |= (1 << ('t' - 'a'));
    base_mask |= (1 << ('i' - 'a'));
    base_mask |= (1 << ('c' - 'a'));
    
    // k-5개 알파벳을 추가로 선택하는 모든 경우 탐색
    go(0, 0, k-5, base_mask);
    
    cout << ret << '\n';
    
    return 0;
}
