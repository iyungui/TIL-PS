import Foundation

func solution(_ M:Int, _ N:Int) -> Int {
    // 한쪽을 1로 만들기까지 count:      2->1 (1)
    // 한쪽 * (다른한쪽 - 1)     :    2(한쪽) * 4(다른한쪽 * 1) = 8
    // 1 + 8 -> 9
    // return (M - 1) + (M * (N - 1))
    return M * N - 1 
}