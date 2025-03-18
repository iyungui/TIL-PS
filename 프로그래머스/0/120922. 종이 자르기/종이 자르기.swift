import Foundation

func solution(_ M:Int, _ N:Int) -> Int {
    // 한쪽을 1로 만들기까지 count:      2->1 (1)
    // 한쪽 * (다른한쪽 - 1)     :    2(한쪽) * 4(다른한쪽 * 1) = 8
    // 1 + 8 -> 9
    var m = M, answer = 0
    while m > 1 {
        answer += 1
        m -= 1
    }
    answer += (M * (N - 1))
    return answer
}