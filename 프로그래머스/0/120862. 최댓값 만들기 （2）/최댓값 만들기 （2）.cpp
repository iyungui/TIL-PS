#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> numbers) {
    int answer = INT_MIN;
    for(int i = 0; i < numbers.size(); i++) {
        for(int j = i + 1; j < numbers.size(); j++) {
            answer = max(answer, numbers[i] * numbers[j]);
        }
    }
    return answer;
}