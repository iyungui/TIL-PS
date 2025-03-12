import Foundation

func solution(_ my_string:String) -> String {
    return my_string.map {
        if $0 >= "A" && $0 <= "Z" {
            return $0.lowercased()
        } else {
            return $0.uppercased()
        }
    }.joined()
}