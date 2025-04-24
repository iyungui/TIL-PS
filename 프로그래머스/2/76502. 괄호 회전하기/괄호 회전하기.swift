import Foundation

func rotate(_ s: String, _ i: Int) -> String {
    if i == 0 { return s }
    return String(s.suffix(s.count - i)) + String(s.prefix(i))
}

func f(_ s: String) -> Bool {
    var stk = Array<Character>()
    for ch in s {
        if stk.isEmpty && (ch == "]" || ch == ")" || ch == "}") {
            return false
        }
        
        if ch == "(" || ch == "[" || ch == "{" {
            stk.append(ch)
        } else if !stk.isEmpty {
            if stk.last! == "(" && ch == ")" { stk.removeLast() }
            else if stk.last! == "[" && ch == "]" { stk.removeLast() }
            else if stk.last! == "{" && ch == "}" { stk.removeLast() }
        }
    }
    return stk.isEmpty ? true : false
}

func solution(_ s:String) -> Int {
    var cnt = 0
    
    for i in 0..<s.count {
        // i만큼 왼쪽으로 회전 (i는 0, 1, 2 ... s.count - 1 까지)
        let rotatedStr = rotate(s, i)
        
        // 올바른 문자열? { cnt += 1 }
        if f(rotatedStr) {
            cnt += 1
        }
    }
    return cnt
}

