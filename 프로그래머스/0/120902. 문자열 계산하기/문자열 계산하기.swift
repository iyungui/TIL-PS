import Foundation

func solution(_ my_string: String) -> Int {
    var plus: Bool = true
    var sum: Int = 0
    var num: String = ""
    
    for char in my_string {
        if char.isNumber {
            num += String(char)
        } else if char == "+" || char == "-" {
            if !num.isEmpty {
                plus ? (sum += Int(num)!) : (sum -= Int(num)!)
                num = ""
            }
            plus = (char == "+")
        }
    }
    
    if !num.isEmpty {
        plus ? (sum += Int(num)!) : (sum -= Int(num)!)
    }
    
    return sum
}