import Foundation

func gcd(_ a: Int, _ b: Int) -> Int {
    if b == 0 {
        return a
    }
    return gcd(b, a % b)
}

func solution(_ a:Int, _ b:Int) -> Int {
    // 기약분수의 분모 구하기
    var denominator = b / gcd(a, b)
    
    // 분모가 2^n * 5^m 형태로 되는지 확인
    // 2로 나눌 수 있을 때까지 나누기
    while denominator % 2 == 0 {
        denominator /= 2
    }
    
    // 5로 나눌 수 있을 때까지 나누기
    while denominator % 5 == 0 {
        denominator /= 5
    }
    
    return denominator == 1 ? 1 : 2
}