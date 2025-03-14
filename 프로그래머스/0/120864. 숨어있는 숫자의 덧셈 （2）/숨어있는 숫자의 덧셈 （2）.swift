import Foundation

func solution(_ my_string:String) -> Int {
    var result = 0
    var str = ""
    for i in my_string {
        if i.isNumber {
            str += String(i)
        } else {
            result += Int(str) ?? 0
            str = ""
        }
    }
    result += Int(str) ?? 0
    return result
}