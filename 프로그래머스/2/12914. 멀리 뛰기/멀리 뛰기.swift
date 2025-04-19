func solution(_ n:Int) -> Int {
    if n == 1 || n == 2 { return n }
    var arr = Array(repeating: 0, count: n)
    
    arr[0] = 1; arr[1] = 2
    for i in 2..<n {
        arr[i] = (arr[i - 1] + arr[i - 2]) % 1234567
    }
    return arr[n - 1]
}