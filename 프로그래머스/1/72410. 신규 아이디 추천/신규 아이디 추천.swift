import Foundation

func solution(_ new_id: String) -> String {
    var ret = ""
    var prev: Character? = nil

    // 1 ~ 3 단계를 한 번에 O(n)
    for ch in new_id {
        let ch = ch.lowercased().first!

        // 허용된 문자인지 확인하고 유효한 문자만 ret에 추가
        if ch.isLetter || ch.isNumber || "-_".contains(ch) {
            ret.append(ch)
            prev = ch
        } else if ch == "." && prev != "." {
            ret.append(ch)
            prev = ch
        }
    }

    // 4. 앞뒤 마침표 제거
    ret = ret.trimmingCharacters(in: CharacterSet(charactersIn: "."))

    // 5. 빈 문자열 처리
    if ret.isEmpty { ret = "a" }

    // 6. 길이 제한
    if ret.count >= 16 {
        ret = String(ret.prefix(15))
        if ret.hasSuffix(".") { _ = ret.popLast() }
    }

    if let last = ret.last {
        while ret.count < 3 {
            ret.append(last)
        }
    }

    return ret
}