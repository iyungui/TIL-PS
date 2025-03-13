import Foundation

func gcd(_ a: Int, _ b: Int) -> Int {
    if b == 0 { return a }
    return gcd(b, a % b)
}

func solution(_ n:Int) -> Int {
    return n / gcd(n, 6)
}