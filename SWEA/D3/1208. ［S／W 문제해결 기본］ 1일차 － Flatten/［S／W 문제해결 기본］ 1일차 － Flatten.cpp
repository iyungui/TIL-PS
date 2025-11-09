#include<bits/stdc++.h>

using namespace std;

const int TC = 10;
const int n = 100;
int dump, a[n];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    for(int t = 1; t <= TC; t++) {
        cin >> dump;

        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // O(n log n)
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            maxHeap.push(a[i]); minHeap.push(a[i]);
        }

        while(dump--) {
            int maxV = maxHeap.top();
            int minV = minHeap.top();

            if(maxV - minV <= 1) break;

            maxHeap.pop();
            minHeap.pop();
            maxHeap.push(maxV - 1);
            minHeap.push(minV + 1);
        }
        int maxV = maxHeap.top();
        int minV = minHeap.top();

        cout << "#" << t << " " << maxV - minV << '\n'; 
    }

    return 0;
}