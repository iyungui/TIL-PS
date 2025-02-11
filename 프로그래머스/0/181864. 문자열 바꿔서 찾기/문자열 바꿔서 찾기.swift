import Foundation

func solution(_ myString:String, _ pat:String) -> Int {
    let temp = myString
        .replacingOccurrences(of: "A", with: "X")  // 임시로 X 사용
        .replacingOccurrences(of: "B", with: "A")
        .replacingOccurrences(of: "X", with: "B")
    return temp.contains(pat) ? 1 : 0
}