import Foundation

func isValid(_ s: String) -> Bool {
    var cur = s
    while true {
        let temp = cur.count
        
        cur = cur.replacingOccurrences(of: "()", with: "")
                 .replacingOccurrences(of: "[]", with: "")
                 .replacingOccurrences(of: "{}", with: "")
        
        if cur.count == temp { break } 
    }
    
    return cur.isEmpty
}

func rotate(_ s: String) -> String {
    let first = s.prefix(1)
    let rest = s.dropFirst()
    return String(rest + first)
}

func solution(_ s:String) -> Int {
    var s = s
    var ret = 0
    for _ in 0..<s.count {
        if isValid(s) { ret += 1 }
        s = rotate(s)
    }
    return ret
}