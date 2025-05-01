import Foundation

func solution(_ clothes:[[String]]) -> Int {
    var dict: [String: Int] = [:]
    
    for item in clothes {
        let category = item[1]
        dict[category, default: 1] += 1
    }
    
    var res = 1
    for cnt in dict.values {
        res *= cnt
    }
    return res - 1
}