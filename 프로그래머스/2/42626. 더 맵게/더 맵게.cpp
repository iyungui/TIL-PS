#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq (scoville.begin(), scoville.end());
    int answer = 0;
    
    while (pq.size() >= 2) {
        if (pq.top() >= K) { return answer; }
        answer++;
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        int c = a + (b * 2);
        pq.push(c);
    }
    if (pq.size() == 1 && pq.top() >= K) { return answer; }
    return -1;
}