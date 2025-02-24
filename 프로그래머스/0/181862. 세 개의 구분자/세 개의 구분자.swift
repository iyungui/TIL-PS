import Foundation

func solution(_ myStr: String) -> [String] {
    let parts = myStr.components(separatedBy: ["a", "b", "c"])
        .filter { !$0.isEmpty }
    return parts.isEmpty ? ["EMPTY"] : parts
}