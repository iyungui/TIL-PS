import Foundation

func solution(_ name:String) -> Int {
    var cnt = 0
    for ch in name {
        let a = Int(ch.asciiValue!) - 65
        cnt += min(a, 26 - a)
    }
    var name = Array(name)
    let n = name.count
    var minMove = n - 1
    for i in 0..<n {
        var next = i + 1
        while next < n && name[next] == "A" {
            next += 1
        }
        let goRight = i * 2 + n - next
        let goLeft = (n - next) * 2 + i
        minMove = min(minMove, goRight, goLeft)
    }
    return cnt + minMove
}