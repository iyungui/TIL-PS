import Foundation

func solution(_ my_str:String, _ n:Int) -> [String] {
    var result: [String] = []
    for i in stride(from: 0, to: my_str.count, by: n) {
        let startIdx = my_str.index(my_str.startIndex, offsetBy: i)
        // let endIdx = my_str.index(startIdx, offsetBy: min(n, my_str.count - i))
        let endIdx = my_str.index(startIdx, offsetBy: n, limitedBy: my_str.endIndex) ?? my_str.endIndex

        let substr = my_str[startIdx..<endIdx]
        result.append(String(substr))
    }
    return result
}