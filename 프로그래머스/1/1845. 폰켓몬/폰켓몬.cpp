#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    set<int> unique_types(nums.begin(), nums.end());
    int select = (int)nums.size() / 2;
    answer = min((int)unique_types.size(), select);
    return answer;
}