#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> dots) {
    // x좌표들의 최대값, 최소값을 구하기 위한 벡터
    vector<int> x_coords;
    // y좌표들의 최대값, 최소값을 구하기 위한 벡터
    vector<int> y_coords;
    
    // 각 점의 x좌표와 y좌표를 분리하여 저장
    for(const auto& dot : dots) {
        x_coords.push_back(dot[0]);
        y_coords.push_back(dot[1]);
    }
    
    // 가로 길이 = x좌표 최대값 - 최소값
    int width = *max_element(x_coords.begin(), x_coords.end()) - 
                *min_element(x_coords.begin(), x_coords.end());
    
    // 세로 길이 = y좌표 최대값 - 최소값
    int height = *max_element(y_coords.begin(), y_coords.end()) - 
                 *min_element(y_coords.begin(), y_coords.end());
    
    // 넓이 = 가로 × 세로
    return width * height;
}