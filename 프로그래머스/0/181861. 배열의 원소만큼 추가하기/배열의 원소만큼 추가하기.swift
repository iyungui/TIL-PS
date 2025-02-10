import Foundation

func solution(_ arr:[Int]) -> [Int] {
    var ret : [Int] = []
    for n in arr {
        for i in 0..<n {
            ret.append(n)
        }
    }
    return ret
}