import Foundation

func solution(_ arr:[Int]) -> [Int] {
    var i = 1
    while i < arr.count { i <<= 1 }
    return arr + Array(repeating: 0, count: abs(arr.count - i))
}