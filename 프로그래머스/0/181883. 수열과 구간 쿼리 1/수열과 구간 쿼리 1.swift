import Foundation

func solution(_ arr:[Int], _ queries:[[Int]]) -> [Int] {
    var ret: [Int] = arr
    queries.forEach {
        for i in $0[0]...$0[1] {
            ret[i] += 1
        }
    }
    return ret
}