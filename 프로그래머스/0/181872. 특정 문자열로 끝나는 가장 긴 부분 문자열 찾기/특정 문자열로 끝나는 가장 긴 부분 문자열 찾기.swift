import Foundation

func solution(_ myString:String, _ pat:String) -> String {
    guard let lastRange = myString.range(of: pat, options: .backwards) else {
        return ""
    }
    return String(myString[..<lastRange.upperBound])
}