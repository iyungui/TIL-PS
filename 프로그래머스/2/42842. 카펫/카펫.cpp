#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total = brown + yellow;
    for(int w = 3; w <= sqrt(total); w++) {
        if(total % w == 0) {
            int h = total / w;
            
            if(2 * (w + h - 2) == brown && (w - 2) * (h - 2) == yellow) {
                return {h, w};
            }
        }
    }
    return {0, 0};
}