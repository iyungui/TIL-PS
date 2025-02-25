import Foundation

func solution(_ arr:[Int]) -> [Int] {
    var i = 0
    var stk: [Int] = []
    while i < arr.count {
        if stk.isEmpty || stk[stk.count - 1] != arr[i] {
            stk.append(arr[i])
            i += 1
        } else if stk[stk.count - 1] == arr[i] {
            stk.remove(at: stk.count - 1)
            i += 1
        }
    }
    return stk.isEmpty ? [-1] : stk
}