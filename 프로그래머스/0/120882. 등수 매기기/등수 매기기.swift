import Foundation

func solution(_ score:[[Int]]) -> [Int] {
    let avg: [Double] = score.map { Double($0[0] + $0[1]) / 2.0 }
    var result: [Int] = Array(repeating: 0, count: avg.count)
    
    for i in (0..<avg.count) {
        var rank: Int = 1
        for j in (0..<avg.count) {
            if avg[i] < avg[j] {
                rank += 1
            }
        }
        result[i] = rank
    }
    
    return result
}