import Foundation

/* short code
func solution(_ bin1:String, _ bin2:String) -> String { 
    var a = Int(bin1, radix: 2)!
    var b = Int(bin2, radix: 2)!
    return String(a + b, radix: 2)
}
*/
func addBinary(_ a: String, _ b: String) -> String {
    
    guard let binaryA = Int(a, radix: 2), 
          let binaryB = Int(b, radix: 2) else {
        return "0"
    }
    
    return String(binaryA + binaryB, radix: 2)
}

func solution(_ bin1:String, _ bin2:String) -> String {    
    return addBinary(bin1, bin2)
}