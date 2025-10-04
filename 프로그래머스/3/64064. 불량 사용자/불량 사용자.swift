import Foundation

func solution(_ user_id:[String], _ banned_id:[String]) -> Int {
    var dict = [String: [Int]]()
    for (idx, user) in user_id.enumerated() {
        let user = Array(user)
        let n = user.count
        
        for mask in 0..<(1 << n) {
            var a = ""
            for i in 0..<n {
                if mask & (1 << i) != 0 { a.append(user[i]) }
                else { a += "*" }
            }
            dict[a, default: []].append(idx)
        }
    }
    
    var nums = [[Int]]()
    for ban in banned_id {
        let d = dict[ban]!
        nums.append(d)
    }
    
    func go() -> Int {
        var s = Set<[Int]>()
        var visited = [Bool](repeating: false, count: user_id.count)
        
        func backtrack(_ depth: Int, _ cur: [Int]) {
            if depth == nums.count {
                s.insert(cur.sorted())
                return
            }
            for i in 0..<nums[depth].count {
                let idx = nums[depth][i]
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