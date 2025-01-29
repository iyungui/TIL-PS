#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    int cnt1 = 0, cnt2 = 0;
    for(int i : num_list) {
        if(i % 2 == 0) cnt1++;
        else cnt2++;
    }
    
    return {cnt1, cnt2};
}