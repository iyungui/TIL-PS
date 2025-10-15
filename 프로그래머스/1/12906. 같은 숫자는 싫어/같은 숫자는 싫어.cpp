#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> ret;
    ret.push_back(arr[0]);
    for (int i = 1; i < arr.size(); i++) {
        if(arr[i] != arr[i - 1]) {
            ret.push_back(arr[i]);
        }
    }
    return ret;
}