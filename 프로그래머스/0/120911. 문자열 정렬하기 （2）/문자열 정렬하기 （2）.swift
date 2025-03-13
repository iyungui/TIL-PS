import Foundation

func solution(_ my_string:String) -> String {
    my_string.lowercased().sorted().map {String($0)}.joined()
}