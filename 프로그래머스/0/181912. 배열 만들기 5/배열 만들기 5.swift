import Foundation

func solution(_ intStrs:[String], _ k:Int, _ s:Int, _ l:Int) -> [Int] {
    var result: [Int] = []
    intStrs.forEach {
        let num = Int(String(Array($0)[s..<s+l]))!
        if(num > k) {
            result.append(num)
        }
    }
    return result
}