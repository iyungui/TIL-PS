import Foundation

func solution(_ n:Int) -> Int {
    // 3의 배수이거나 3이 들어간 숫자는 이전 값에서 +1을 한번 더 해야 함
    var prev: Int = 0
    for i in (1...n) {
        prev += 1
        while prev % 3 == 0 || String(prev).contains("3") {
            prev += 1
        }
    }
    return prev
}