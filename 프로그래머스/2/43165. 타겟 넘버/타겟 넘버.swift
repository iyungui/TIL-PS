import Foundation

func solution(_ numbers:[Int], _ target:Int) -> Int {
    let ret: Int = go(0, 0, numbers, target)
    return ret
}

func go(_ index: Int, _ sum: Int, _ numbers: [Int], _ target: Int) -> Int {
    if index == (numbers.count) {
        if sum == target {
            return 1
        }
        return 0
    }
    
    let a = sum + numbers[index]
    let b = sum - numbers[index]
    
    return go(index + 1, a, numbers, target) + go(index + 1, b, numbers, target)
}