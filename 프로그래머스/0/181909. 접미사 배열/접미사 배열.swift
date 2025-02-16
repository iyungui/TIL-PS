import Foundation

func solution(_ my_string:String) -> [String] {
    let length = my_string.count
    return (0..<length).map {
        String(my_string.suffix($0 + 1))
    }.sorted()
}