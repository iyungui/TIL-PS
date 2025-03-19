import Foundation

func gcd(_ a: Int, _ b: Int) -> Int {
    if b == 0 {
        return a
    }
    return gcd(b, a % b)
}

func isPrimeNumber(_ n: Int) -> Bool {
    if n < 2 { return false }
    for i in 2..<n {
        if n % i == 0 { return false }
    }
    return true
}

func solution(_ a:Int, _ b:Int) -> Int {
    var a = a, b = b
    // 1. 기약분수로 만들기
    var divisor = gcd(a, b)
    while divisor != 1 {
        a /= divisor
        b /= divisor
        divisor = gcd(a, b)
    }
    print(a, b)
    
    // 2. 소인수 찾기
    if b == 1 { return 1 }
    for i in (2...b) {
        if b % i == 0 && isPrimeNumber(i) {
            if i == 2 || i == 5 { continue }
            return 2
        }
    }
    
    return 1
}