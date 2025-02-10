import Foundation

func solution(_ num_str:String) -> Int {
    var sum = 0
    for char in num_str {
        sum += Int(String(char))!
    }
    return sum
    // S1
    
    // var sum = 0
    // for char in num_str {
    //     sum += Int(String(char))!
    // }
    // return sum
    
    // S2
    //     return num_str.map { Int(String($0))! }.reduce(0, +)
    // return num_str.map { Int(String($0))! }.reduce(0, +)
    
}