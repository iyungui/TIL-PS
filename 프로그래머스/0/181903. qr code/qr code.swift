import Foundation

func solution(_ q:Int, _ r:Int, _ code:String) -> String {
    var result: String = ""
    let code = Array(code)
    for (offset, element) in code.enumerated() {
        if(offset % q == r) {
            result += String(element)
        }
    }
    return result
}