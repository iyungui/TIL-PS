import Foundation

func isPrime(_ n: Int) -> Bool {
    if n <= 1 { return false }
    if n == 2 { return true }
    if n % 2 == 0 { return false }
    var i = 3
    while (i * i) <= n {
        if n % i == 0 { return false }
        i += 2
    }
    return true
}

func solution(_ n:Int, _ k:Int) -> Int {
    let kBase = String(n, radix: k)
    let parts = kBase.split(separator: "0").map { Int($0)! }
    return parts.map { isPrime($0) ? 1 : 0 }.reduce(0, +)
}