import Foundation

func solution(_ date1:[Int], _ date2:[Int]) -> Int {
    let a: Int = Int(date1.reduce("") { $0 + String($1) })!
    let b: Int = Int(date2.reduce("") { $0 + String($1) })!
    return a < b ? 1 : 0
}