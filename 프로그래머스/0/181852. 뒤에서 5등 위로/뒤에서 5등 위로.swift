import Foundation

func solution(_ num_list:[Int]) -> [Int] {
    let sortedArray = num_list.sorted()
    return Array(sortedArray[5...])
}