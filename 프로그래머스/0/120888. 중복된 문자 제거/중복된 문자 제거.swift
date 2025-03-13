import Foundation

func solution(_ my_string:String) -> String {
    var result = ""
    for c in my_string {
        if !result.contains(c) {
            result += String(c)
        }
    }
    return result
}