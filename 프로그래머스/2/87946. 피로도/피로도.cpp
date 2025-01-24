#include <bits/stdc++.h>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    sort(dungeons.begin(), dungeons.end());
    do {
        int cnt = 0;
        int temp = k;
        for(vector<int> v : dungeons) {
            // 최소필요 피로도 v[0]
            // 소모 필요도 v[1]
            if(temp >= v[0]) {
                temp -= v[1];
                cnt++;
            }
        }
        answer = max(answer, cnt);
    } while(next_permutation(dungeons.begin(), dungeons.end()));
    return answer;
}