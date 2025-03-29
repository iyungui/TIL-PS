import Foundation

func solution(_ myString:String) -> [Int] {
    let arr = myString.components(separatedBy: "x")
    return arr.map { $0.count }
}