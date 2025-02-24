import Foundation

func solution(_ myStr: String) -> [String] {
    let parts = myStr.split { "abc".contains($0) }.map { String($0) }
    return parts.isEmpty ? ["EMPTY"] : parts
}