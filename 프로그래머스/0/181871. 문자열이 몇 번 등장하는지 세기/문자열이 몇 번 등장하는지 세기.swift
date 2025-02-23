import Foundation

func solution(_ myString:String, _ pat:String) -> Int {
    return stride(from: 0, through: myString.count - pat.count, by: 1)
        .filter { myString[myString.index(myString.startIndex, offsetBy: $0)...]
        .prefix(pat.count) == pat }
        .count
}