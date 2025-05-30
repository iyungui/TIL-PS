import Foundation

func solution(_ numbers:[Int], _ target:Int) -> Int {
    var cnt = 0
    func go(_ index: Int, _ sum: Int) {
        if index == numbers.count {
            if sum == target {
                cnt += 1
            }
            return
        }

        go(index + 1, sum + numbers[index])
        
        go(index + 1, sum - numbers[index])
    }
    
    go(0, 0)
    return cnt
}