func solution(_ n:Int) -> Int {
    var f: [Int] = [0, 1]
    for i in 2...n {
        f.append((f[i - 1] + f[i - 2]) % 1234567)
    }
    return f[n]
}