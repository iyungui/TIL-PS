import Foundation

func solution(_ relation:[[String]]) -> Int {
    let n = relation.count
    let m = relation[0].count
    var combis = Array(repeating: [[Int]](), count: m + 1)
    
    for i in 1...m {    // O(2^m - 1)
        combis[i] = combination(m, i)
    }
    
    func check(_ combi: [Int]) -> Bool {
        let picked = (0..<n).map { i in combi.map { relation[i][$0] } }
        return Set(picked).count == n
    }
    
    var sets = Set<Set<Int>>()
    for combi: [[Int]] in combis {
        for cc: [Int] in combi {
            let curSet = Set(cc)
            var flag = true
            for s in sets {
                if s.isSubset(of: curSet) { flag = false; break }
            }
            
            if flag && check(cc) {
                sets.insert(curSet)
            }
        }
    }
    return sets.count
}

// 1부터 m개뽑는 모든 조합 생성 
func combination(_ n: Int, _ r: Int) -> [[Int]] {
    var ret = [[Int]]()
        
    func backtrack(_ start: Int, _ cur: [Int]) {
        if cur.count == r {
            ret.append(cur)
            return
        }
        for i in start..<n {
            backtrack(i + 1, cur + [i])
        }
    }
    
    backtrack(0, [])
    return ret
}
    