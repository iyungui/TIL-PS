#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int total = brown + yellow;
    
    for(int width = 3; width <= sqrt(total); width++) {
        if(total % width == 0) {
            int height = total / width;
            
            if ((width - 2) * (height - 2) == yellow && 
                2 * (width + height - 2) == brown) {
                return {height, width};
            }
        }
    }
    return {0, 0};
}