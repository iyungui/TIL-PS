import Foundation

func solution(_ n:Int) -> [Int] {
    var factors = Set<Int>()
    var temp = n
    var i = 2
    while i * i <= temp {
        while temp % i == 0 {
            factors.insert(i)
            temp /= i
        }
        i += 1
    }
    if temp > 1 { factors.insert(temp) }
    return factors.sorted()
}