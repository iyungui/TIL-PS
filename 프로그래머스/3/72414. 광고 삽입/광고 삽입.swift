import Foundation

func toSec(_ str: String) -> Int {
    let a = str.split(separator: ":").map { Int($0)! }
    return a[0] * 60 * 60 + a[1] * 60 + a[2]
}

func toTime(_ num: Int) -> String {
    var h = "\(num / 3600)"
    while h.count < 2 {
        h = "0" + h
    }
    var m = "\((num % 3600) / 60)"
    while m.count < 2 {
        m = "0" + m
    }
    var s = "\(num % 3600 % 60)"
    while s.count < 2 {
        s = "0" + s
    }
    return h + ":" + m + ":" + s
}

func solution(_ play_time:String, _ adv_time:String, _ logs:[String]) -> String {
    if play_time == adv_time { return "00:00:00" }
    
    let totalSec = toSec(play_time)
    let advSec = toSec(adv_time)
    
    // 시청자 수
    var diff = Array(repeating: 0, count: totalSec + 1)
    
    for log in logs {
        let a = log.split(separator: "-").map { String($0) }
        let (start, end) = (toSec(a[0]), toSec(a[1]))
        diff[start] += 1
        diff[end] -= 1
    }
    
    for i in 1..<diff.count {
        diff[i] += diff[i - 1]
    }
    
    // 누적 시청 시간
    var psum = Array(repeating: 0, count: totalSec + 1)
    for i in 1..<psum.count {
        psum[i] = psum[i - 1] + diff[i - 1]
    }
    
    // 누적 재생시간 구간 (L, R)
    var maxPSum = 0
    var ret = 0
    for l in 0...totalSec - advSec {
        let r = l + advSec
        let sum = psum[r] - psum[l]
        if sum > maxPSum {
            maxPSum = sum
            ret = l
        }
    }
    return toTime(ret)
}