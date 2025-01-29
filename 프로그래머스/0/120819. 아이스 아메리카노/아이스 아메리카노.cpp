#include <string>
#include <vector>

using namespace std;

vector<int> solution(int money) {
    return {(int)money / 5500,(int)money % 5500};
}