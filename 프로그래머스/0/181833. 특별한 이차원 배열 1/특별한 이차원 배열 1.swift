import Foundation

func solution(_ n:Int) -> [[Int]] {
    var ret: [[Int]] = []
    for i in 0..<n {
        var row: [Int] = []
        for j in 0..<n {
            if(i == j) { row.append(1) }
            else { row.append(0) }
        }
        ret.append(row)
    }
    return ret
}