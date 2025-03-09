import Foundation

func solution(_ my_string: String, _ indices: [Int]) -> String {
    let indicesSet = Set(indices)
    var result = ""
    for (index, char) in my_string.enumerated() {
        if !indicesSet.contains(index) {
            result.append(char)
        }
    }
    return result
}