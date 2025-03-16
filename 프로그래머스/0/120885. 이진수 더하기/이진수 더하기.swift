import Foundation

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