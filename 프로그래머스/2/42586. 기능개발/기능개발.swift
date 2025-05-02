import Foundation

func solution(_ progresses: [Int], _ speeds: [Int]) -> [Int] {
    // 각 작업이 완료되는데 필요한 일수 계산
    var daysRequired: [Int] = []
    
    for i in 0..<progresses.count {
        let remainingProgress = 100 - progresses[i]
        // 나누어 떨어지지 않으면 하루 더 필요 (올림 효과)
        let days = remainingProgress / speeds[i] + (remainingProgress % speeds[i] > 0 ? 1 : 0)
        daysRequired.append(days)
    }
    
    var result: [Int] = []
    var index = 0
    
    // 모든 작업을 처리할 때까지 반복
    while index < daysRequired.count {
        let currentDay = daysRequired[index]
        var count = 1
        
        // 현재 작업 이후의 작업들 중 같이 배포될 수 있는 작업 카운트
        var nextIndex = index + 1
        while nextIndex < daysRequired.count && daysRequired[nextIndex] <= currentDay {
            count += 1
            nextIndex += 1
        }
        
        // 결과 배열에 현재 배포에 포함된 기능 수 추가
        result.append(count)
        
        // 인덱스 업데이트
        index = nextIndex
    }
    
    return result
}