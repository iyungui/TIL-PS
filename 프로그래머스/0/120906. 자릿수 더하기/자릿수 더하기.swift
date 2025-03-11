import Foundation

func solution(_ n:Int) -> Int {
    // var n = n, sum = 0
    // while(n > 0) {
    //     sum += n % 10
    //     n /= 10
    // }
    // return sum
    
    return String(n).map { Int(String($0))! }.reduce(0, +)
}