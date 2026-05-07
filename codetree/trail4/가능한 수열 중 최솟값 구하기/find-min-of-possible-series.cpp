#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> b;

bool is_equal(int e1, int s1, int e2, int s2) {
    int len = e1-s1;
    for(int i = 0; i <= len; i++) {
        if(b[s1+i] != b[s2+i]) return 0;    // 하나라도 다른 경우
    }
    return 1;
}

bool chk() {
    int len = 1;
    while(1) {
        int e1 = b.size()-1;
        int s1 = e1-len+1;
        int e2 = s1-1;
        int s2 = e2-len+1;

        if(s2 < 0) break;
        
        if(is_equal(e1,s1,e2,s2)) return 0;

        len++;
    }

    return 1;
}

void go(int k) {
    if(k == N) {
        for(int i = 0; i < N; i++) cout << b[i];
        exit(0);
    }

    for(int i = 4; i <= 6; i++) {
        b.push_back(i);
        if(chk()) go(k+1);
        b.pop_back();
    }
}

int main() {
    cin >> N;
    go(0);
    return 0;
}