import Foundation

func solution(_ my_string:String, _ overwrite_string:String, _ s:Int) -> String {
    var result = my_string
    let startIdx = my_string.index(my_string.startIndex, offsetBy: s)
    let endIdx = my_string.index(startIdx, offsetBy: overwrite_string.count)
    result.replaceSubrange(startIdx..<endIdx, with: overwrite_string)
    return result
}