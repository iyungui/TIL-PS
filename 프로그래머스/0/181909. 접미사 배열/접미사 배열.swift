import Foundation

func solution(_ my_string: String) -> [String] {
    return (0..<my_string.count).map { 
        String(my_string.suffix(my_string.count - $0))
    }.sorted()
}