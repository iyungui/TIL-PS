import Foundation

func solution(_ s:String) -> Int {
    guard s.count % 2 == 0 else { return 0 }
    var stk: Array<Character> = []
    var s = Array(s)
    
    for ch in s {
        if stk.isEmpty {
            stk.append(ch)
        } else {
            if stk.last == ch {
                stk.removeLast()
            } else {
                stk.append(ch)
            }
        }
    }
    return stk.isEmpty ? 1 : 0
}