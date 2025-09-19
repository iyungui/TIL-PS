import Foundation
func solution(_ n:Int, _ tops:[Int]) -> Int {
    let MOD = 10007
    var a = Array(repeating: 0, count: n + 1)
    var b = Array(repeating: 0, count: n + 1)

    a[1] = 1
    b[1] = tops[0] == 1 ? 3 : 2

    if n == 1 {
        return a[1] + b[1]
    }

    for i in 2...n {
        if tops[i - 1] == 1 {
            a[i] = (a[i - 1] + b[i - 1]) % MOD
            b[i] = (2 * a[i - 1] + 3 * b[i - 1]) % MOD
        } else if tops[i - 1] == 0 {
            a[i] = (a[i - 1] + b[i - 1]) % MOD
            b[i] = (a[i - 1] + 2 * b[i - 1]) % MOD
        }
    }

    return (a[n] + b[n]) % MOD
}
