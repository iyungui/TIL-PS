#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> numbers) {
    // 조합을 이용한 풀이 O(n ^ 2)
    // int answer = INT_MIN;
    // for(int i = 0; i < numbers.size(); i++) {
    //     for(int j = i + 1; j < numbers.size(); j++) {
    //         answer = max(answer, numbers[i] * numbers[j]);
    //     }
    // }
    // return answer;
    
    // sort 사용 O(logn)
    sort(numbers.begin(), numbers.end());
    int n = numbers.size();
    return max(numbers[n - 1] * numbers[n - 2], numbers[0] * numbers[1]);
}