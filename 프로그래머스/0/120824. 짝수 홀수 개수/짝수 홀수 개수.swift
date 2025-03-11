import Foundation

func solution(_ num_list:[Int]) -> [Int] {
    var odd = 0, even = 0
    num_list.forEach {
        $0 % 2 == 0 ? (even += 1) : (odd += 1)
    }
    return [even, odd]
}