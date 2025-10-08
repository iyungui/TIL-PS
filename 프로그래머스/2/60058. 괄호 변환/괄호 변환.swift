import Foundation

func findUV(_ str: String) -> (String, String) {
    var a = 0, b = 0
    let arr = Array(str)
    for i in 0..<arr.count {
        if arr[i] == "(" { a += 1 }
        else { b += 1 }
        if a == b {
            return (String(arr[0...i]), String(arr[(i + 1)...]))
        }
    }
    return (str, "")
}

func check(_ str: String) -> Bool {
    var stk = [Character]()
    
    for ch in str {
        if ch == "(" { stk.append(ch) }
        else if !stk.isEmpty && stk.last! == "(" { _ = stk.popLast() }
        else { return false }
    }
    return stk.isEmpty
}

func solution(_ p:String) -> String {
    guard !p.isEmpty else { return "" }
    if p == "()" { return "()" }
    
    let (u, v) = findUV(p)
    
    if check(u) { return u + solution(v) }
    
    var ret = "("
    ret += solution(v)
    ret += ")"
    let temp = u.dropFirst().dropLast()
    ret += String(temp.map { $0 == "(" ? ")" : "(" })
    
    return ret
}