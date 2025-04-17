func solution(_ n:Int) -> Int {
    var f: [Int] = [0, 1]
    for k in 2...n {
        f.append((f[k - 1] + f[k - 2]) % 1234567)
    }
    return f[n]
}