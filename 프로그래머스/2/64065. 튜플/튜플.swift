import Foundation

func solution(_ s:String) -> [Int] {
    let parts = s.components(separatedBy: "},")
    var sets = [[Int]]()
    for part in parts {
        let numbers = part.replacingOccurrences(of: "{", with: "")
                          .replacingOccurrences(of: "}", with: "")
                          .split(separator: ",").compactMap { Int($0) }
        sets.append(numbers)
    }
    
    sets.sort { $0.count < $1.count }
    
    var ret = [Int]()
    var seen = Set<Int>()
    
    for set in sets {
        for num in set {
            if !seen.contains(num) {
                ret.append(num)
                seen.insert(num)
            }
        }
    }
    
    return ret
}