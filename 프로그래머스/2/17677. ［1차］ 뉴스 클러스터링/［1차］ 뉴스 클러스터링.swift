func solution(_ str1:String, _ str2:String) -> Int {
    let A = go(str1.lowercased())
    let B = go(str2.lowercased())
    if A.isEmpty && B.isEmpty { return 65536 }
    let (inter, union) = solve(A, B)
    return Int(Double(inter) / Double(union) * 65536)
}

func go(_ str: String) -> [String] {
    var ret = [String]()
    var str = Array(str)
    for i in 0..<(str.count - 1) {
        if str[i].isLetter && str[i + 1].isLetter {
            ret.append(String(str[i]) + String(str[i + 1]))
        }
    }   
    return ret
}

func solve(_ a: [String], _ b: [String]) -> (Int, Int) {
    var cnt: [String: Int] = [:]
    var cnt2: [String: Int] = [:]    
    for aa in a { cnt[aa, default: 0] += 1 }
    for bb in b { cnt2[bb, default: 0] += 1 }

    let sets = Set(a + b)
    var (inter, union) = (0, 0)
    
    for str in sets {
        inter += min(cnt[str, default: 0], cnt2[str, default: 0])
        union += max(cnt[str, default: 0], cnt2[str, default: 0])
    }
    return (inter, union)
}