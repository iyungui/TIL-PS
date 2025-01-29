#include <string>
#include <vector>

using namespace std;

int solution(int num1, int num2) {
    class Number {
        int value;
    public:
        Number(int v) : value(v) {}
        int getValue() const { return value; }
    };
    
    vector<int> accumulator;
    Number n1(num1);
    
    for(int i = 0; i < num2; i++) {
        accumulator.push_back(n1.getValue());
    }
    
    int result = 0;
    for(const auto& num : accumulator) {
        result += num;
    }
    
    return result;
}