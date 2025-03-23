import Foundation

func gcd(_ a: Int, _ b: Int) -> Int {
    if b == 0 {
        return a
    }
    return gcd(b, a % b)
}

func lcm(_ a: Int, _ b: Int) -> Int {
    return a / gcd(a, b) * b
}

func solution(_ numer1:Int, _ denom1:Int, _ numer2:Int, _ denom2:Int) -> [Int] {
    // denom1, denom2의 최소공배수.를 구하고, 각 최소공배수 되는 만큼, numer1,2에도 적용   
    var mul1: Int = 1
    var mul2: Int = 1
    
    let lcmValue = lcm(denom1, denom2)
    while denom1 * mul1 != lcmValue {
        mul1 += 1
    }
    while denom2 * mul2 != lcmValue {
        mul2 += 1
    }
    var a = (numer1 * mul1) + (numer2 * mul2)
    var b = denom1 * mul1
    let gcdValue = gcd(a, b)
    a /= gcdValue
    b /= gcdValue
    return [a, b]
}