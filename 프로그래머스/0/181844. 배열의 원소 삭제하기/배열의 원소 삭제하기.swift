import Foundation

func solution(_ arr:[Int], _ delete_list:[Int]) -> [Int] {
    let arr = arr
    let result = arr.filter { !delete_list.contains($0) }
    return result
}