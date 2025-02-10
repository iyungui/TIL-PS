import Foundation

func solution(_ num_list:[Int]) -> [Int] {
    let answer = num_list.sorted()
    return Array(answer.prefix(5))
}