#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array) {
    int idx = 0;
    int mx = 0;
    for(int i = 0; i < array.size(); i++) {
        if(mx < array[i]) {
            mx = array[i];
            idx = i;
        }
    }
    return {mx, idx};
}