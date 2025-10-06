import Foundation

func solution(_ s:String) -> Int {
    let dict: [String: Int] = [
        "zero": 0,
        "one": 1,
        "two": 2,
        "three": 3,
        "four": 4,
        "five": 5,
        "six": 6,
        "seven": 7,
        "eight": 8,
        "nine": 9
    ]
    
    let s = Array(s)
    var i = 0
    var ret = [Int]()
    
    while i < s.count {
        if s[i].isNumber {
            ret.append(Int(String(s[i]))!)
            i += 1
            continue
        }
        
        for len in [5, 4, 3] where len + i <= s.count {
            let word = s[i..<(i + len)].reduce("") { $0 + String($1) }
            if let num = dict[word] {
                ret.append(num)
                i += len
                break
            }
        }
    }
    
    return Int(ret.map { String($0) }.reduce("", +))!
}