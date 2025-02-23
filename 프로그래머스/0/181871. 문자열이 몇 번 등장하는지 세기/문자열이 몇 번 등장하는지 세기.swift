import Foundation

// S1
// func solution(_ myString:String, _ pat:String) -> Int {
//     return stride(from: 0, through: myString.count - pat.count, by: 1)
//         .filter { myString[myString.index(myString.startIndex, offsetBy: $0)...]
//         .prefix(pat.count) == pat }
//         .count
// }

// S2
func solution(_ myString: String, _ pat: String) -> Int {
    var count = 0
    let strArr = Array(myString)
    let patArr = Array(pat)
    
    // 가능한 모든 시작 위치에서 패턴 검사
    for i in 0...strArr.count - patArr.count {
        // var isMatch = true
        // // 패턴의 각 문자 비교
        // for j in 0..<patArr.count {
        //     if strArr[i + j] != patArr[j] {
        //         isMatch = false
        //         break
        //     }
        // }
        // if isMatch {
        //     count += 1
        // }
        if strArr[i..<i+patArr.count].elementsEqual(patArr) {
            count += 1
        }
    }
    return count
}