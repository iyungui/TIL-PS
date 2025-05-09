
import Foundation
let input = readLine()!.split(separator: " ").map { Int($0)! }
let n = input[0], k = input[1]
let temperatures = readLine()!.split(separator: " ").map { Int($0)! }

// 첫 번째 윈도우 합 계산
var currentSum = 0
for i in 0..<k {
    currentSum += temperatures[i]
}

// 최대값을 현재 윈도우의 합으로 초기화
var maxSum = currentSum

// 슬라이딩 윈도우
for i in k..<n {
    // 새 요소 추가 및 가장 오래된 요소 제거
    currentSum = currentSum + temperatures[i] - temperatures[i-k]
    maxSum = max(maxSum, currentSum)
}

print(maxSum)