import Foundation

func solution(_ arr:[Int]) -> [Int] {
    var stk = [Int]()
    for num in arr {
        if stk.isEmpty || stk.last! != num {
            stk.append(num)
        } else {
            stk.popLast()
        }
    }
    return stk.isEmpty ? [-1] : stk
}