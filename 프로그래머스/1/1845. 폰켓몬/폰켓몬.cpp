#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums) {
    unordered_set<int> st(nums.begin(), nums.end());
    return min((int)st.size(), (int)nums.size() / 2);
}