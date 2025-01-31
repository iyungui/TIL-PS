#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> numbers, string direction) {
    if(direction[0] == 'r') {
        rotate(numbers.rbegin(), numbers.rbegin() + 1, numbers.rend());
    } else if(direction[0] == 'l') {
        rotate(numbers.begin(), numbers.begin() + 1, numbers.end());
    }
    return numbers;
}