import Foundation

func solution(_ id_list:[String], _ report:[String], _ k:Int) -> [Int] {
    var ret = Array(repeating: 0, count: id_list.count)
    
    var dict = [String: [String]]()
    var cnt = [String: Int]()
    
    for id in id_list {
        dict[id] = []
        cnt[id] = 0
    }
    
    for r in report {
        let parts = r.split(separator: " ").map { String($0) }
        let a = parts[0], b = parts[1]
        if dict[a]!.contains(b) {
            continue
        }
        cnt[b]! += 1
        dict[a]!.append(b)
    }
    
    var cnt2 = [String: Int]()
    
    for (a, b) in dict {
        for i in b {
            if cnt[i]! >= k {
                cnt2[a, default: 0] += 1
            }
        }
    }
    
    for (idx, id) in id_list.enumerated() {
        ret[idx] = cnt2[id, default: 0]
    }
    
    return ret
}