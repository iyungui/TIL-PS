#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> numbers) {
    /* 조합을 이용한 풀이
    int ret = 0;
    for(int i = 0; i < numbers.size(); i++) {
        for(int j = i + 1; j < numbers.size(); j++) {
            ret = max(ret, numbers[i] * numbers[j]);
        }
    }
    return ret;
    
    */
    
    // sort (내림차순) 활용 풀이
    sort(numbers.begin(), numbers.end(), greater<int>());
    return numbers[0] * numbers[1];
}