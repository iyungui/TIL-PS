import Foundation

func solution(_ s:String) -> [Int] {
    var cnt1 = 0    // 변환 횟수
    var cnt2 = 0    // 제거된 0의 개수
    var s = s
    
    while s != "1" {
        // (제거할 0의 개수: 원래 개수 - 1만 있는 것의 개수
        let onlyOneCount = s.replacingOccurrences(of: "0", with: "").count
        cnt2 += (s.count - onlyOneCount)
        s = String(onlyOneCount, radix: 2)
        cnt1 += 1
    }
    
    return [cnt1, cnt2]
}