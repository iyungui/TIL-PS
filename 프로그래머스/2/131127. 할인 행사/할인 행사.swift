import Foundation

func solution(_ want:[String], _ number:[Int], _ discount:[String]) -> Int {
    var wantDict: [String: Int] = [:]
    for (value, count) in zip(want, number) {
        wantDict[value] = count
    }
    var res = 0
    for start in 0...discount.count - 10 {
        var window: [String: Int] = [:]
        for i in start..<(start + 10) {
            window[discount[i], default: 0] += 1
        }
        var flag = true
        for (value, count) in wantDict {
            if window[value, default: 0] < count {
                flag = false
                break
            }
        }
        if flag { res += 1 }
    }
    return res
}