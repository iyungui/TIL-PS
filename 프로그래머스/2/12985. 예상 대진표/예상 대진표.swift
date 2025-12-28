import Foundation

func solution(_ n:Int, _ a:Int, _ b:Int) -> Int {
    var round = 0
    var a = a
    var b = b
    
    // 두 참가자의 번호가 같아질 때까지 반복
    while a != b {
        a = (a + 1) / 2
        b = (b + 1) / 2
        round += 1
    }
    
    return round
}