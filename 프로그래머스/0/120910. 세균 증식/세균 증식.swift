import Foundation

func solution(_ n:Int, _ t:Int) -> Int {
    var n = n, t = t
    while t > 0 {
        n *= 2
        t -= 1
    }
    return n
}