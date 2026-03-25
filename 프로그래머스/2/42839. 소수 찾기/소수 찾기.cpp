#include <bits/stdc++.h>

using namespace std;

bool isused[10];
unordered_set<int> st;

bool is_prime(int n) {
    if(n < 2) return 0;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return 0;
    }
    return 1;
}

void dfs(string cur, string& numbers) {
    if(cur.size()) {
        int n = stoi(cur);
        if(is_prime(n)) {
            st.insert(n);
        }
    }
    for(int i = 0; i < (int)numbers.size(); i++) {
        if(isused[i]) continue;
        isused[i] = 1;
        dfs(cur + numbers[i], numbers);
        isused[i] = 0;
    }
}

int solution(string numbers) {
    dfs("", numbers);
    return (int)st.size();
}