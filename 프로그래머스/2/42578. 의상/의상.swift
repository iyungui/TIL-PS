import Foundation

func solution(_ clothes:[[String]]) -> Int {
    var dict = clothes.reduce(into: [String: Int]()) { $0[$1[1], default: 0] += 1 }
    return dict.values.reduce(1) { $0 * ($1 + 1) } - 1
}