import Foundation

func solution(_ progresses:[Int], _ speeds:[Int]) -> [Int] {
    var days = [Int]()
    for (progress, speed) in zip(progresses, speeds) {
        var remain = 100 - progress
        var day = 0
        while remain > 0 {
            remain -= speed
            day += 1
        }
        days.append(day)
    }
    var cur = days[0]
    var cnt = 1
    var ret = [Int]()
    
    for i in 1..<days.count {
        if cur < days[i] {
            ret.append(cnt)
            cnt = 1
            cur = days[i]
        } else { cnt += 1 }
    }
    if cnt > 0 { ret.append(cnt) }
    return ret
}