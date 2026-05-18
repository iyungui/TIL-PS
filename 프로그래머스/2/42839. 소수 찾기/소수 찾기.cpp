#include <bits/stdc++.h>

// numbers의 길이가 7이하
// 순열 => 해당 조합이 소수라면 cnt++

using namespace std;

int isused[10];
unordered_set<int> st;

bool isPrime(int x) {
    if(x < 2) return 0;
    for(int i = 2; i*i <= x; i++) {
        if(x % i == 0) return 0;
    }
    return 1;
}

void dfs(string cur, string& numbers) {
    if(cur.size()) {
        int num = stoi(cur);
        if(isPrime(num)) st.insert(num);
    }
    for(int i = 0; i < (int)numbers.size(); i++) {
        if(isused[i]) continue;
        isused[i] = true;
        dfs(cur + numbers[i], numbers);
        isused[i] = false;
    }
}

int solution(string numbers) {
    dfs("", numbers);
    return (int)st.size();
}