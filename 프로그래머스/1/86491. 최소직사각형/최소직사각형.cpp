#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int m_w = 0;
    int m_h = 0;
    for(vector<int> p : sizes) {
        int w = max(p[0], p[1]);
        int h = min(p[0], p[1]);
        
        m_w = max(m_w, w);
        m_h = max(m_h, h);
    }
    return m_w * m_h;
}