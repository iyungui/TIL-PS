import Foundation

func solution(_ new_id:String) -> String {
    return verify(new_id) ? new_id : solve(new_id)
}

private func verify(_ str: String) -> Bool {
    // 아이디의 길이는 3 ~ 15자여야 한다.
    guard str.count >= 3 && str.count <= 15 else { return false }

    // 마침표는 처음과 끝에 사용할 수 없다.
    if str.first! == "." || str.last! == "." { return false }
    
    // 아이디는 알파벳 소문자, 숫자, 빼기, 밑줄, 마침표만 가능하다.
    var prev: Character? = nil
    for ch in str {
        if ch.isLetter && ch.isLowercase { continue }
        // 마침표는 연속으로 사용할 수 없다.
        if ch == "." { 
            if prev == "." { return false }
            prev = ch
            continue
        }
        if ch.isNumber || ch == "-" || ch == "_" || ch == "." { continue }
        return false
    }
    return true
}

private func solve(_ str: String) -> String {
    // 모든 대문자를 대응되는 소문자로 치환한다.
    var ret = str.lowercased()
    
    // 알파벳 소문자, 숫자, 빼기, 밑줄, 마침표를 제외한 모든 문자를 제거한다.
    ret = ret.filter { ($0.isLetter && $0.isLowercase) || $0.isNumber || $0 == "-" || $0 == "_" || $0 == "." }
    
    // 마침표가 2번 이상 연속된 부분은 하나의 마침표로 치환한다.
    while ret.contains("..") {
        ret = ret.replacingOccurrences(of: "..", with: ".")
    }
    
    // 마침표가 처음이나 끝에 위치한다면 제거한다.
    ret = ret.trimmingCharacters(in: CharacterSet(charactersIn: "."))
    
    // 빈 문자열이라면 a를 대입한다
    if ret.isEmpty { ret += "a" }
    
    // 길이가 16자 이상이면, 첫 15개 문자 제외한 나머지 문자를 모두 제거한다.
    if ret.count >= 16 {
        ret = String(ret.prefix(15))
        // 만약 제거 후 마침표가 ret 끝에 위치한다면 끝 마침표는 제거한다
        if ret.last == "." { _ = ret.removeLast() }
    }
    

    
    // 길이가 2자 이하라면, 길이가 3이 될 때까지 마지막 문자를 더한다
    if let last = ret.last {
        while ret.count <= 2 {
            ret.append(last)
        }
    }
    
    return ret
}