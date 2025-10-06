func solution(_ n:Int, _ t:Int, _ m:Int, _ p:Int) -> String {
    var arr: [Character] = []
    for i in arr.count..<(t * m) {
        let b = String(i, radix: n)
        for bb in b { arr.append(bb) }
    }
    var ret = ""
    var i = p - 1
    while i < arr.count {
        ret.append(arr[i])
        if ret.count == t { break }
        i += m
    }
    return ret.uppercased()
}

