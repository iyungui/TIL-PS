import Foundation

func solution(_ queue1: [Int], _ queue2: [Int]) -> Int {
    let arr = queue1 + queue2
    let totalSum = arr.reduce(0, +)
    guard totalSum % 2 == 0 else { return -1 }
    let target = totalSum / 2
    let n = queue1.count
    
    var left = 0
    var right = n - 1

    var currentSum = queue1.reduce(0, +)
    var cnt = 0

    while cnt <= 4 * n {
        if currentSum == target { return cnt }
        else if currentSum < target {
            right = (right + 1) % (2 * n)
            currentSum += arr[right]
        } else {
            currentSum -= arr[left]
            left = (left + 1) % (2 * n)
        }
        cnt += 1
    }

    return -1
}