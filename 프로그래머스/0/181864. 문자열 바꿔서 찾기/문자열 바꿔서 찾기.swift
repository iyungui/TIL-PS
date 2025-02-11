import Foundation

func solution(_ myString:String, _ pat:String) -> Int {
    // let temp = myString
    //     .replacingOccurrences(of: "A", with: "X")  // 임시로 X 사용
    //     .replacingOccurrences(of: "B", with: "A")
    //     .replacingOccurrences(of: "X", with: "B")
    // return temp.contains(pat) ? 1 : 0
    let changed = String(myString.map { $0 == "A" ? "B" : "A" })
    return changed.contains(pat) ? 1 : 0
}