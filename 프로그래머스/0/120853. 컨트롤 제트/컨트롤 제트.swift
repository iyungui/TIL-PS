import Foundation

func solution(_ s:String) -> Int {
    let arr: [String] = s.split(separator: " ").map { String($0) }
    var prev: String = ""
    var result: [String] = []
    for str in arr {
        if str == "Z" {
            result.removeLast()
        } else {
            result.append(str)
            prev = str
        }
    }
    return result.reduce(0) { $0 + Int($1)! }
}