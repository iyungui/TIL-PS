import Foundation

func solve(_ str: String) -> Bool {
    let words = ["aya", "ye", "woo", "ma"]
    var str = str
    for word in words {
        str = str.replacingOccurrences(of: word, with: "-")
    }
    let arr = str.components(separatedBy: "-").joined()
    return arr.isEmpty ? true : false
}

func solution(_ babbling:[String]) -> Int {
    return babbling.filter { solve($0) }.count
}