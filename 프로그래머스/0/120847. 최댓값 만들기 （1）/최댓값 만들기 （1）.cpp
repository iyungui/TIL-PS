#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> numbers) {
    int ret = 0;
    for(int i = 0; i < numbers.size(); i++) {
        for(int j = i + 1; j < numbers.size(); j++) {
            ret = max(ret, numbers[i] * numbers[j]);
        }
    }
    return ret;
}