import Foundation

func solution(_ my_strings:[String], _ parts:[[Int]]) -> String {
    return zip(my_strings, parts).map { (str: String, part: [Int]) -> String in
        let start = str.index(str.startIndex, offsetBy: part[0])
        let end = str.index(str.startIndex, offsetBy: part[1])
        return String(str[start...end])
    }.joined()
}