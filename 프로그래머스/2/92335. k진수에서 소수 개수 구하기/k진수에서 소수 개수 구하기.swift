import Foundation

func solution(_ n:Int, _ k:Int) -> Int {
    let s = String(n, radix: k)
        
    
    
    return s.split(separator: "0").filter { p in
            !p.isEmpty &&
            isPrime(Int(p)!) &&
        (s.contains("0\(p)0") || s.contains("\(p)0") || s.contains("0\(p)") || s.contains(p))
        }
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