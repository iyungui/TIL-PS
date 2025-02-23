import Foundation

func solution(_ myString:String, _ pat:String) -> String {
    let parts = myString.components(separatedBy: pat)
    return parts[0..<parts.count - 1].joined(separator: pat) + pat
}