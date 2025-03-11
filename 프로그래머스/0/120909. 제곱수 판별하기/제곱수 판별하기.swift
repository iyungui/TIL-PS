import Foundation

func solution(_ n:Int) -> Int {
    var flag: Bool = false
    (1...n).forEach {
        if $0 * $0 == n { flag = true }
    }
    return flag == true ? 1 : 2
}