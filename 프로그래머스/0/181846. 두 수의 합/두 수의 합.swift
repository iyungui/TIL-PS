import Foundation

func solution(_ a:String, _ b:String) -> String {
    let digitsA = a.reversed().map { Int(String($0))! }
    let digitsB = b.reversed().map { Int(String($0))! }
    let maxLength = max(digitsA.count, digitsB.count)
    var result = [Int]()
    var carry = 0
    
    for i in 0..<maxLength {
        let digitA = i < digitsA.count ? digitsA[i] : 0
        let digitB = i < digitsB.count ? digitsB[i] : 0
        
        let sum = digitA + digitB + carry
        result.append(sum % 10)
        carry = sum / 10
    }
    if carry > 0 {
        result.append(carry)
    }
    return result.reversed().map { String($0) }.joined()
}