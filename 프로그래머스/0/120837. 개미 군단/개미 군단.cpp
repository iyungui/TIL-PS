#include <string>
#include <vector>

using namespace std;

int solution(int hp) {
    int answer = 0;
    int a[3] = {5, 3, 1};
    int i = 0;
    while(hp > 0 && i < 3) {
        if(hp >= a[i]) hp -= a[i], answer++;
        else i++;
    }
    return answer;
}