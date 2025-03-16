import Foundation

func solution(_ n:Int) -> [Int] {
    var factors = Set<Int>()
    var n = n
    for i in (2...n) {
        while n % i == 0 {
            factors.insert(i)
            n /= i
        }
    }
    if n > 1 { factors.insert(n) }
    return factors.sorted()
}