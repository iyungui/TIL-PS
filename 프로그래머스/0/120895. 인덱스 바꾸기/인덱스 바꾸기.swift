import Foundation

func solution(_ my_string:String, _ num1:Int, _ num2:Int) -> String {
    var my_string = Array(my_string)
    my_string.swapAt(num1, num2)
    return String(my_string)
}