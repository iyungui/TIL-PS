import Foundation

func solution(_ s:String) -> Int {
    var result: [Int] = []
    for str in s.components(separatedBy: " ") {
        if str == "Z" {
            result.popLast()
        } else {
            result.append(Int(str)!)
        }
    }
    return result.reduce(0, +)
}