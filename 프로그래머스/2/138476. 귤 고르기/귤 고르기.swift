import Foundation

func solution(_ k:Int, _ tangerine:[Int]) -> Int {
    var cnt = [Int: Int]()
    for i in tangerine {
        cnt[i, default: 0] += 1
    }
    // 값만 필요하기 때문에
    let sortedArr = cnt.values.sorted(by: >)
    
    var selected = 0
    var typeCount = 0
    
    for i in sortedArr {
        selected += i
        typeCount += 1
        if selected >= k {
            break
        }
    }
    
    return typeCount
}