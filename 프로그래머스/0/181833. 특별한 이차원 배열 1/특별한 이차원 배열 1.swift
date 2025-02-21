import Foundation

func solution(_ n: Int) -> [[Int]] {
    // var ret = Array(repeating: Array(repeating: 0, count: n), count: n)
    // for i in 0..<n {
    //     ret[i][i] = 1
    // }
    // return ret
    
    return (0..<n).map {
        var arr = Array(repeating: 0, count: n)
        arr[$0] = 1
        return arr
    }
}