import Foundation

func solution(_ my_string:String, _ m:Int, _ c:Int) -> String {
    
    // S1: stride - String 그대로 (String.index 타입 사용)
    // return stride(from: c - 1, to: my_string.count, by: m)
    //     .map { String(my_string[my_string.index(my_string.startIndex, offsetBy: $0)]) }.joined()
        
    // S2: stride - String 을 [Character]로 형변환 후 사용
    // let arr = Array(my_string)
    // return stride(from: c - 1, to: arr.count, by: m)
    // .map { String(arr[$0]) }
    // .joined()
    
    // 문자열을 m개씩 나누어서 접근
    return my_string.enumerated()
        .filter { $0.offset % m == c - 1 }
        .map { String($0.element) }
        .joined()
}