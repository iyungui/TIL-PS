import Foundation

func solution(_ n:Int, _ k:Int) -> Int {
    return String(n, radix: k)
        .split(separator: "0")
        .compactMap { Int($0) }
        .filter { isPrime($0) }
        .count
}

private func isPrime(_ n: Int) -> Bool {
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