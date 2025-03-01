import Foundation

func solution(_ my_strings:[String], _ parts:[[Int]]) -> String {
    return zip(my_strings, parts).map { (str, part) in
        String(str.prefix(part[1] + 1).suffix(part[1] - part[0] + 1))
    }.joined()
}