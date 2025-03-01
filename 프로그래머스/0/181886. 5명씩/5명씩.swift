import Foundation

func solution(_ names:[String]) -> [String] {
    return stride(from: 0, to: names.count, by: 5).map {
        return names[$0]
    }
}