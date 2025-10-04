import Foundation

func solution(_ user_id:[String], _ banned_id:[String]) -> Int {
    // userId 전처리
    var dict = [String: [Int]]()
    for (idx, user) in user_id.enumerated() {
        let user = Array(user)
        let n = user.count
        for mask in 0..<(1 << n) {
            var a = ""
            for i in 0..<n {
                if mask & (1 << i) != 0 {
                    a.append(user[i])
                } else {
                    a += "*"
                }
            }
            dict[a, default: []].append(idx)
        }
    }
    var arr = [[Int]]()
    for ban in banned_id {
        let idxs = dict[ban]!
        arr.append(idxs)
    }
    
    func go() -> Int {
        var s = Set<[Int]>()
        var visited = Array(repeating: false, count: user_id.count)
        func backtrack(_ depth: Int, _ cur: [Int]) {
            if cur.count == arr.count {
                s.insert(cur.sorted())
                return
            }
            for i in 0..<arr[depth].count {
                let idx = arr[depth][i]
                if visited[idx] { continue }
                visited[idx] = true
                backtrack(depth + 1, cur + [idx])
                visited[idx] = false
            }
        }
        
        backtrack(0, [])
        return s.count
    }

    return go()
}
