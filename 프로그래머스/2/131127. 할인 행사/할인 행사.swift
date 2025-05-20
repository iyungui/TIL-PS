import Foundation

func solution(_ want:[String], _ number:[Int], _ discount:[String]) -> Int {
    var dict: [String: Int] = [:]
    for (item, num) in zip(want, number) {
        dict[item, default: 0] = num
    }
    var ret = 0
    for start in 0...discount.count - 10 {
        var window: [String: Int] = [:]
        for i in start..<(start + 10) {
            window[discount[i], default: 0] += 1
        }
        var flag = true
        for (value, count) in dict {
            if window[value, default: 0] < count {
                flag = false
                break
            }
        }
        if flag { ret += 1 }
    } 
    return ret
}