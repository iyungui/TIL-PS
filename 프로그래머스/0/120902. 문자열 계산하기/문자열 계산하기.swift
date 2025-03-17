import Foundation

func solution(_ my_string: String) -> Int {
    my_string
        .replacingOccurrences(of: " - ", with: " + -")
        .components(separatedBy: " + ")
        .reduce(0,  { $0 + Int($1)! })
}