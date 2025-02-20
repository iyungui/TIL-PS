import Foundation

func solution(_ numLog:[Int]) -> String {
    var prev: Int = numLog.first!
    var ret: String = ""
    for i in (1..<numLog.count) {
        let diff = numLog[i] - prev
        switch(diff) {
            case 1:
                ret.append("w")
            case -1:
                ret.append("s")
            case 10:
                ret.append("d")
            case -10:
                ret.append("a")
            default:
                break
        }
        prev = numLog[i]
    }
    return ret
}