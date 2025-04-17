import Foundation

func solution(_ brown: Int, _ yellow: Int) -> [Int] {
    // 카펫의 총 격자 수는 갈색 + 노란색
    let total = brown + yellow
    
    // 가능한 가로, 세로 크기 탐색
    // 가로 길이는 세로 길이보다 크거나 같음
    for height in 3...Int(sqrt(Double(total))) {
        if total % height == 0 {
            let width = total / height
            
            // 테두리를 제외한 내부 영역(노란색)의 격자 수 계산
            let innerYellow = (width - 2) * (height - 2)
            
            // 노란색 영역이 주어진 yellow와 일치하는지 확인
            if innerYellow == yellow {
                return [width, height]
            }
        }
    }
    
    return [] // 해가 없는 경우 (문제 조건상 항상 해가 존재)
}