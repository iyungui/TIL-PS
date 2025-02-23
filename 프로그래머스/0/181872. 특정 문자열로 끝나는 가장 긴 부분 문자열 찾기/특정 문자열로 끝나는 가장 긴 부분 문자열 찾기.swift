import Foundation

func solution(_ myString:String, _ pat:String) -> String {
    if let lastRange = myString.range(of: pat, options: .backwards) {
        return String(myString[..<lastRange.upperBound])
    }
    return ""
}