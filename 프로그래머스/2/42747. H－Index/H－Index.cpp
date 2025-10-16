#include<bits/stdc++.h>
using namespace std;
int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), greater<int>());
    
    int h_index = 0;
    for (int i = 0; i < citations.size(); i++) {
        // i+1편의 논문이 각각 i+1번 이상 인용되었는지 확인
        if (citations[i] >= i + 1) {
            h_index = i + 1;
        }
    }
    
    return h_index;
}