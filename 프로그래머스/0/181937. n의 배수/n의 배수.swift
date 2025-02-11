import Foundation

func solution(_ num:Int, _ n:Int) -> Int {
    // num % n == 0 ? 1 : 0
    return num.isMultiple(of: n) ? 1 : 0
}