import Foundation

func solution(_ num_list:[Int]) -> Int {
    var multiple: Int = num_list.reduce(1, *)
    var sum: Int = num_list.reduce(0, +)
    
    return multiple > sum * sum ? 0 : 1
}