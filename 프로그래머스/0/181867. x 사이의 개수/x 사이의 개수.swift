import Foundation

func solution(_ myString:String) -> [Int] {
    let arr: [String] = myString.components(separatedBy: "x")
    return arr.map { $0.count }
}