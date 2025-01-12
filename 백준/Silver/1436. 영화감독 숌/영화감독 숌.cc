#include <iostream>
#include <string>
using namespace std;

bool isDoomNumber(int num) {
    string numStr = to_string(num);
    int consecutive_six = 0;
    int max_consecutive_six = 0;
    
    for (char digit : numStr) {
        if (digit == '6') {
            consecutive_six++;
            max_consecutive_six = max(max_consecutive_six, consecutive_six);
        } else {
            consecutive_six = 0;
        }
    }
    
    return max_consecutive_six >= 3;
}

int findNthDoomNumber(int n) {
    int count = 0;
    int num = 666;
    
    while (true) {
        if (isDoomNumber(num)) {
            count++;
            if (count == n) {
                return num;
            }
        }
        num++;
    }
}

int main() {
    int N;
    cin >> N;
    cout << findNthDoomNumber(N) << endl;
    
    return 0;
}