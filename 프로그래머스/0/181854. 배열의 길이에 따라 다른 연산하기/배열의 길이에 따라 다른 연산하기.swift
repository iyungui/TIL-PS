import Foundation

func solution(_ arr:[Int], _ n:Int) -> [Int] {
    let startIndex = arr.count % 2 == 1 ? 0 : 1 // 홀수면 0부터, 짝수면 1부터 시작
    var arr = arr
    stride(from: startIndex, to: arr.count, by: 2).forEach {
        // index
        arr[$0] = arr[$0] + n
    }
    return arr
}