func solution(_ n:Int, _ t:Int, _ m:Int, _ p:Int) -> String {
    let needed = p + (t - 1) * m    // 필요한 문자열의 길이
    
    var arr: [Character] = []
    var num = 0
    while arr.count < needed {
        arr += String(num, radix: n).uppercased()
        num += 1
    }
    
    var ret = ""
    for i in stride(from: p - 1, to: arr.count, by: m) {
        ret.append(arr[i])
        if ret.count == t { break }
    }
    return ret
}