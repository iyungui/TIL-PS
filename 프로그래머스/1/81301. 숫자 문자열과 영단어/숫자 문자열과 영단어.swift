import Foundation

func solution(_ s:String) -> Int {
    let numbers: [(str: String, num: String)] = [
        ("zero", "0"),
        ("one", "1"),
        ("two", "2"),
        ("three", "3"),
        ("four", "4"),
        ("five", "5"),
        ("six", "6"),
        ("seven", "7"),
        ("eight", "8"),
        ("nine", "9")
    ]
    
    var ret = s
    for n in numbers {
        ret = ret.replacingOccurrences(of: n.str, with: n.num)
    }
    
    return Int(ret)!
}
