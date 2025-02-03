#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> array, int n) {
    int answer = 0;
    int temp = INT_MAX;
    for(int i : array) {
        int _diff = abs(i - n);
        if(_diff < temp) {
            temp = _diff;
            answer = i;
        } else if(_diff == temp) {
            if(answer > i) answer = i;
        }
    }
    return answer;
}