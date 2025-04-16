import Foundation

func solution(_ s:String) -> Bool {
    var stk = Array<Character>()
    var s: Array<Character> = Array(s)
    for ch in s {
        if ch == "(" {
            stk.append(ch)
        } else if ch == ")" {
            if stk.isEmpty { return false }
            if stk.last! == "(" { stk.removeLast() }
        }
    }
    return stk.isEmpty ? true : false
}