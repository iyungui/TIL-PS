import Foundation

func solution(_ strArr:[String]) -> Int {
    var cnt = Array(repeating: 0, count: 31) 
    strArr.forEach {
        cnt[$0.count] += 1
    }
    return cnt.max()!
}