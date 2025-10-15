import Foundation

func solution(_ priorities:[Int], _ location:Int) -> Int {
    var queue = [(Int, Int)]()
    for (idx, prior) in priorities.enumerated() {
        queue.append((idx, prior))
    }
    var queueIdx = 0
    var cnt = 0
    
    while queueIdx < queue.count {
        let cur = queue[queueIdx]
        queueIdx += 1
        var temp = queueIdx
        var flag = false
        
        while temp < queue.count {
            if cur.1 < queue[temp].1 {
                flag = true
                break
            }
            temp += 1
        }
        if flag {
            queue.append(cur)
        } else {
            cnt += 1
            if cur.0 == location {
                return cnt
            }
        }
    }
    
    return cnt
}