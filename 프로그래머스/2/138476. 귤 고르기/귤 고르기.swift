import Foundation

func solution(_ k:Int, _ tangerine:[Int]) -> Int {
    var cnt: [Int: Int] = [:]
    
    for i in tangerine {
        cnt[i, default: 0] += 1
    }
    let sortedCnt = cnt.values.sorted(by: >)
    
    var res = 0
    var selected = 0
    for i in sortedCnt {
        selected += i
        res += 1
        if selected >= k { return res }
    }
    
    return res
}