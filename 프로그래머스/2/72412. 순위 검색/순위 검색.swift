import Foundation
func solution(_ info:[String], _ query:[String]) -> [Int] {
    // info 전처리 (score는 [Int] 형태로 저장)
    // 비트마스킹 (2^4)
    var db = [String: [Int]]()
    for i in info {
        let parts = i.split(separator: " ").map { String($0) }
        let score = Int(parts[4])!

        for mask in 0..<(1 << 4) {
            var key = ""
            for j in 0..<4 {
                if (mask & (1 << j)) != 0 {
                    key += parts[j]
                } else {
                    key += "-"
                }
            }
            db[key, default: []].append(score)
        }
    }
    // 점수 오름차순 정렬 (이분탐색을 위해) O(N log N)
    db.forEach { 
        db[$0] = $1.sorted()
    }

    var ret = [Int]()

    for q in query {
        let parts = q.replacingOccurrences(of: " and ", with: " ").split(separator: " ").map { String($0) }
        let key = parts[0] + parts[1] + parts[2] + parts[3]
        let score = Int(parts[4])!

        if let scores: [Int] = db[key] {
            // 이분탐색으로 score 이상인 점수의 개수 찾기
            var left = 0
            var right = scores.count

            while left < right {
                let mid = (left + right) / 2
                if scores[mid] >= score {
                    right = mid
                } else {
                    left = mid + 1
                }
            }
            ret.append(scores.count - left)
        } else {
            ret.append(0)
        }
    }

    return ret
}
