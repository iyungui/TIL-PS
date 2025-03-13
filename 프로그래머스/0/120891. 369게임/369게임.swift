import Foundation

func solution(_ order:Int) -> Int {
    return String(order)
    .filter { String($0) == "3" || String($0) == "6" || String($0) == "9" }
    .count
}