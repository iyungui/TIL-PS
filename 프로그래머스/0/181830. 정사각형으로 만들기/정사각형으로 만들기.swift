import Foundation

func solution(_ arr: [[Int]]) -> [[Int]] {
    var arr = arr
    let n = arr.count // 행의 수
    let m = arr.isEmpty ? 0 : arr[0].count // 열의 수
    
    if n < m {
        // 행이 열보다 적으면 행을 추가
        for _ in 0..<(m - n) {
            arr.append(Array(repeating: 0, count: m))
        }
    } else if n > m {
        // 열이 행보다 적으면 각 행에 열을 추가
        for i in 0..<n {
            arr[i].append(contentsOf: Array(repeating: 0, count: n - m))
        }
    }
    
    return arr
}