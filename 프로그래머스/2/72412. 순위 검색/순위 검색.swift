import Foundation

func solution(_ info: [String], _ query: [String]) -> [Int] {
    // O(50,000 * 100,000) -> O(n log n + q log n)
    var dict: [String: [Int]] = [:]

    for i in info {
        let a = i.split(separator: " ").map { String($0) }
        let score = Int(a[4])!
        

        for mask in 0..<(1 << 4) {
            var key = ""
            for j in 0..<4 {
                if mask & (1 << j) != 0 {
                    key += a[j]
                } else {
                    key += "-"
                }
            }
            dict[key, default: []].append(score)
        }
    }
    dict.forEach {
        dict[$0] = $1.sorted()
    }
    
    var ret = [Int]()

    for q in query {
        let a = q.replacingOccurrences(of: " and ", with: " ").split(separator: " ").map { String($0) }
        let key = (a[0] + a[1] + a[2] + a[3])
        let score = Int(a[4])!

        if let scores = dict[key] {
            var left = 0, right = scores.count

            while left < right {
                let mid = (left + right) / 2
                if scores[mid] >= score { right = mid }
                else { left = mid + 1 }
            }
            ret.append(scores.count - left)
        } else {
            ret.append(0)
        }
    }

    return ret
}