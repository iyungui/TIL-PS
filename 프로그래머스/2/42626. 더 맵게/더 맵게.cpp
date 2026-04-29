#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    
    int cnt = 0;
    while(1) {
        if(pq.size() && pq.top() >= K) return cnt;
        if((int)pq.size() >= 2) {
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            int c = a + (b * 2);
            pq.push(c);
        } 
        else break;
        cnt++;
    }
    
    return -1;
}