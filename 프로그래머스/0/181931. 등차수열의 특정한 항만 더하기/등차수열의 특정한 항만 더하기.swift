import Foundation

func solution(_ a:Int, _ d:Int, _ included:[Bool]) -> Int {
    var ret = 0
    for (index, isIncluded) in included.enumerated() {
        if(isIncluded) {
            ret += a + (d * index)
        }
    }
    return ret
}