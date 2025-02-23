import Foundation

func solution(_ myString:String, _ pat:String) -> String {
    
    /* S1 반복문
    let strArr = Array(myString)
    let patArr = Array(pat)
    
    for i in (0...strArr.count - patArr.count).reversed() {
        let currentSlice = Array(strArr[i..<i+patArr.count])
        if currentSlice == patArr {
            return String(strArr[...(i+patArr.count-1)])
        }
    }
    return ""
    */
    
    // S2 components
    // let parts = myString.components(separatedBy: pat)
    // parts.map { print($0) }
    // return parts[0..<parts.count - 1].joined(separator: pat) + pat
    
    
    // S3 range(option: backwards), upperBound
    // guard let lastRange = myString.range(of: pat, options: .backwards) else {
    //     return ""
    // }
    // return String(myString[..<lastRange.upperBound])
    
    // S4 suffix, dropLast
    var str = myString
    while(str.hasSuffix(pat) == false) {
        str = String(str.dropLast())
    }
    return str
}