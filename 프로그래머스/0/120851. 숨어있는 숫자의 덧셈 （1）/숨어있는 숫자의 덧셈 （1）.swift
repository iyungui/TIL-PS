import Foundation

func solution(_ my_string:String) -> Int {
    my_string
        // .filter { $0 >= "0" && $0 <= "9" }
        .filter { $0.isNumber }
        .map { Int(String($0))! }
        .reduce(0, +)
}