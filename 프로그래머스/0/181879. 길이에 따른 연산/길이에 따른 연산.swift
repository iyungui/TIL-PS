import Foundation

func solution(_ num_list:[Int]) -> Int {
    if num_list.count >= 11 {
        return num_list.reduce(0, +)
    }
    return num_list.reduce(1, *)
}