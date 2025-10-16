#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums) {
    int answer = (int)nums.size() / 2;
    sort(nums.begin(), nums.end());
    
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    return min(answer, (int)nums.size());
}