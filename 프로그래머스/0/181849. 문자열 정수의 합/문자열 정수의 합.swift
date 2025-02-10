import Foundation

func solution(_ num_str:String) -> Int {
    var sum = 0
    for char in num_str {
        sum += Int(String(char))!
    }
    return sum
}