import Foundation

func solution(_ myString:String) -> String {
    var result: String = ""
    myString.forEach {
        if $0 == "a" {
            result.append("A")
        } else if $0 >= "B" && $0 <= "Z" {  // A가 아닌 대문자 알파벳
            result.append($0.lowercased())
        } else {    // A
            result.append(String($0))
        }
    }
    return result
}