import Foundation

func solution(_ gems: [String]) -> [Int] {
    let totalTypes = Set(gems).count

    var gemCount = [String: Int]()

    var left = 0
    var minLength = Int.max
    var ret = [1, gems.count]

    for right in 0..<gems.count {
        gemCount[gems[right], default: 0] += 1

        while gemCount.count == totalTypes {
            let length = right - left + 1
            if length < minLength {
                minLength = length
                ret = [left + 1, right + 1]
            }

            gemCount[gems[left]]! -= 1
            if gemCount[gems[left]]! == 0 {
                gemCount.removeValue(forKey: gems[left])
            }
            left += 1
        }
    }

    return ret
}