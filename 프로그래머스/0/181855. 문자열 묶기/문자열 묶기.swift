import Foundation

func solution(_ strArr:[String]) -> Int {
    var cnt = Array(repeating: 0, count: 31) 
    strArr.forEach {
        cnt[$0.count] += 1
    }
    var ret = 0
    for i in 1...30 {
        ret = max(ret, cnt[i])
    }
    return ret
}