import Foundation

func solution(_ intStrs:[String], _ k:Int, _ s:Int, _ l:Int) -> [Int] {
    // return intStrs.map { Int($0.prefix(s + l).suffix(l))! }.filter { $0 > k }
    
    return intStrs.map {
        let startIdx = $0.index($0.startIndex, offsetBy: s)
        let endIdx = $0.index(startIdx, offsetBy: l)
        return Int(String($0[startIdx..<endIdx]))!
    }.filter { $0 > k }
}