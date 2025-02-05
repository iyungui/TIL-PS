#include <string>
#include <vector>
using namespace std;

long long solution(string numbers) {
    vector<string> nums = {"zero", "one", "two", "three", "four", "five", 
                          "six", "seven", "eight", "nine"};
    string answer = "";
    string temp = "";
    
    for(char c : numbers) {
        temp += c;
        for(int i = 0; i < nums.size(); i++) {
            if(temp == nums[i]) {
                answer += to_string(i);
                temp = "";
                break;
            }
        }
    }
    
    return stoll(answer);
}