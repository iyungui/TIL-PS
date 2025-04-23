import Foundation

func solution(_ want:[String], _ number:[Int], _ discount:[String]) -> Int {
    var dict: [String: Int] = [:]
    for (value, count) in zip(want, number) {
        dict[value] = count
    }
    
    var res = 0
    
    for i in 0...(discount.count - 10) {
        
        var windowDict: [String: Int] = [:]
        
        for j in i..<(i + 10) {
            windowDict[discount[j], default: 0] += 1
        }
        
        var isMatch: Bool = true
        
        for (value, count) in dict {
            if windowDict[value, default: 0] < count {
                isMatch = false
                break
            }
        }
        
        if isMatch { res += 1 }
    }
    return res
}