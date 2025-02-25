import Foundation

func solution(_ a:String, _ b:String) -> String {
    var result = ""
    var carry = 0
    var i = a.count - 1, j = b.count - 1
    let aArr = Array(a).map { Int(String($0))! }, 
        bArr = Array(b).map { Int(String($0))! }
    
    while i >= 0 || j >= 0 || carry > 0 {
        var sum = carry
        
        if i >= 0 {
            sum += aArr[i]
            i -= 1
        }
        if j >= 0 {
            sum += bArr[j]
            j -= 1
        }
        result = "\(sum % 10)" + result
        carry = sum / 10
    }
    return result
}
