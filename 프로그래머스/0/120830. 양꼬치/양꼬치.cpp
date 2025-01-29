#include <string>
#include <vector>

using namespace std;

int solution(int n, int k) {
    return ((12000 * n) + (k - (n / 10)) * 2000);
}