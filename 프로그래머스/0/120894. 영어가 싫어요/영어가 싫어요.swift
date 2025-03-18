import Foundation

func solution(_ numbers:String) -> Int64 {
    let num: [String] = [
        "zero", "one", "two", "three",
        "four", "five", "six", "seven", "eight", "nine"
    ]
    var str: String = ""
    var result: String = ""
    for i in numbers {
        str += String(i)
        for (offset, element) in num.enumerated() {
            if str == element {
                result.append(String(offset))
                str = ""
                break
            }
        }
    }
    return Int64(result)!
}