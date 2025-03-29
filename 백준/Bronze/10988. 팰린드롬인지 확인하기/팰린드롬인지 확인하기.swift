import Foundation

var s = readLine()!

func solution(_ s: String) -> Int {
    let temp = String(s.reversed())
    
    return s == temp ? 1 : 0
}

print((solution(s)))