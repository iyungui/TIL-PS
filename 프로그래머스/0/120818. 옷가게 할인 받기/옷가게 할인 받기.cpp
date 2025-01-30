#include <string>
#include <vector>

using namespace std;

int solution(int price) {
    double answer = 0;
    if(price >= 500000) {
        answer = 0.2;
    } else if(price >= 300000) {
        answer = 0.1;
    } else if(price >= 100000) {
        answer = 0.05;
    }
    return price * (1 - answer);
}