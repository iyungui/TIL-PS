#include <bits/stdc++.h>
using namespace std;

int K, N;
vector<int> selected;

void printPermutation() {
    for(int i = 0; i < (int)selected.size(); i++) cout << selected[i] << " ";
    cout << '\n';
}

void go(int cnt) {
    // N개 숫자를 다 뽑은 경우
    if(cnt == N) {
        printPermutation();
        return;
    }
    for(int i = 1; i <= K; i++) {
        if(cnt >= 2 && i == selected[cnt-1] && i == selected[cnt-2]) continue;
        selected.push_back(i);
        go(cnt+1);
        selected.pop_back();
    }
}

int main() {
    cin >> K >> N;
    
    go(0);
    return 0;
}