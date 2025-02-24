import Foundation

func solution(_ order:[String]) -> Int {
    order.map { $0.contains("cafelatte") ? 5000 : 4500 }.reduce(0, +)
}