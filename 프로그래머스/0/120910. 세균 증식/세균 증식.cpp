#include <string>
#include <vector>

using namespace std;

int solution(int n, int t) {
    while(t--) {
        n *= 2;
    }
    return n;
}