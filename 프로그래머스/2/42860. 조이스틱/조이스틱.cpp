#include <bits/stdc++.h>

using namespace std;

int solution(string name) {
    int answer = 0;
    int n = name.size();
    int moves = n - 1;
    for(int i = 0; i < n; i++) {
        int up = (int)(name[i] - 'A');
        int down = (int)('Z' - name[i]) + 1;
        int up_down = min(up, down);
        answer += up_down;
        
        int next = i + 1;
        while(next < n && name[next] == 'A') next++;
        
        int front_and_back = i*2 + (n-next);
        int back_and_front = (n-next) * 2 + i;
        
        moves = min({moves, front_and_back, back_and_front});
    }
    return answer + moves;
}

/*
J A N

i = J
next = N

i -> next (n - 1)

*/