#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> array) {
    sort(array.begin(), array.end());
    int mid = (int)array.size() / 2;
    return array[mid];
}