import Foundation

func solution(_ num: Int, _ total: Int) -> [Int] {
    // 시작 숫자 x를 계산합니다
    // num개의 연속된 수가 x, x+1, x+2, ... x+(num-1)일 때
    // 합이 total이 되는 x를 구합니다
    let x = (total - (num * (num - 1) / 2)) / num
    
    // 시작 숫자 x부터 연속된 num개의 숫자를 배열에 담습니다
    var result: [Int] = []
    for i in 0..<num {
        result.append(x + i)
    }
    
    return result
}