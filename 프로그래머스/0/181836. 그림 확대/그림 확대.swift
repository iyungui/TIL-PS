import Foundation

func solution(_ picture:[String], _ k:Int) -> [String] {
    var result: [String] = []
    for row in picture {
        var str: String = ""
        for i in row {
            str += String(repeating: i, count: k)
        }
        for _ in 0..<k {
            result.append(str)
        }
    }
    return result
}