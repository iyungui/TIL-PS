import Foundation

func solution(_ want:[String], _ number:[Int], _ discount:[String]) -> Int {
    // zip을 사용하여 want와 number를 딕셔너리 wantDict에 저장
    var wantDict: [String: Int] = [:]
    for (value, count) in zip (want, number) {
        wantDict[value] = count
    }
    
    var res = 0
    
    // discounts 목록에서, 가능한 모든 10일 기간 (윈도우)에 대해 반복.
    for start in 0...discount.count - 10 {
    
        // 각 윈도우 마다, window 딕셔너리 새로 생성
        var windowDict: [String: Int] = [:]
        
        // 해당 start 로부터 10일 동안 discount의 제품과 수량을 window 딕셔너리에 기록
        for i in start..<(start + 10) {
            windowDict[discount[i], default: 0] += 1
        }
        
        var isMatch = true
        // 원하는 모든 제품이 충분한 수량으로 할인 되는지 확인
        for (value, count) in wantDict {
            if windowDict[value, default: 0] < count {
                isMatch = false
                break
            }
        }
        // 모든 제품이 충분히 할인된다면 res 1 증가
        if isMatch { res += 1 }
    }
    return res
}