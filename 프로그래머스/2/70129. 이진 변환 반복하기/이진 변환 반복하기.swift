import Foundation

func solution(_ s:String) -> [Int] {
    var x: String = s
    var cnt1 = 0, cnt2 = 0
    while x != "1" {
        let removeZeroCnt = x.replacingOccurrences(of: "0", with: "").count
        cnt2 += x.count - removeZeroCnt
        x = String(removeZeroCnt, radix: 2)
        cnt1 += 1
    }
    return [cnt1, cnt2]
}