import Foundation

func solution(_ myString:String, _ pat:String) -> String {
    let strArr = Array(myString)
    let patArr = Array(pat)
    
    for i in (0...strArr.count - patArr.count).reversed() {
        let currentSlice = Array(strArr[i..<i+patArr.count])
        if currentSlice == patArr {
            return String(strArr[...(i+patArr.count-1)])
        }
    }
    return ""
}