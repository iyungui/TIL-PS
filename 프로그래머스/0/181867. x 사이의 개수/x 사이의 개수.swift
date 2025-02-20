import Foundation

func solution(_ myString:String) -> [Int] {
    myString.components(separatedBy: "x").map { $0.count }
}