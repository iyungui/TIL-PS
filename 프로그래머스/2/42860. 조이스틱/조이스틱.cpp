#include <bits/stdc++.h>

using namespace std;

int solution(string name) {
    int n = name.size();
    int answer = 0;
    int moved = n - 1;
    for(int i = 0; i < n; i++) {
        int up = (int)name[i] - 'A';
        int down = ('Z' - (int)name[i]) + 1;
        answer += min(up, down);
        
        int nxt = i + 1;
        while(nxt < n && name[nxt] == 'A') nxt++;
        
        int right_first = i * 2 + (n - nxt);
        int left_first = (n - nxt) * 2 + i;
        moved = min({moved, right_first, left_first});    
    }
    return answer + moved;
}