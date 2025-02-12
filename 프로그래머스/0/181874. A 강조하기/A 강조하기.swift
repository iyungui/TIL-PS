import Foundation

func solution(_ myString:String) -> String {
    // myString.map { $0.lowercased() == "a" ? "A" : $0.lowercased() }.joined()
    myString.lowercased().replacingOccurrences(of: "a", with: "A")
}