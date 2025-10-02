import Foundation

func solution(_ gems:[String]) -> [Int] {
    var minLength = 100004
    var l = 0
    var ret = [l, gems.count]
    var gemsCount = [String: Int]()
    var total = Set(gems).count
    for r in 0..<gems.count {
        gemsCount[gems[r], default: 0] += 1
        while gemsCount.count == total {
            let length = r - l + 1
            if length < minLength {
                minLength = length
                ret = [l + 1, r + 1]
            }
            gemsCount[gems[l]]! -= 1
            if gemsCount[gems[l]]! == 0 {
                gemsCount.removeValue(forKey: gems[l])
            }
            l += 1
        }
    }
    return ret
}