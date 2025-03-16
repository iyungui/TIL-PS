import Foundation

func solution(_ n:Int) -> [Int] {
    var factors = Set<Int>()
    var n = n
    var i = 2
    while i * i <= n {
        while n % i == 0 {
            print(n)
            factors.insert(i)
            n /= i
        }
        i += 1
    }
    if n > 1 { factors.insert(n) }
    return factors.sorted()
}