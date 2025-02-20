import Foundation

func solution(_ arr:[Int], _ delete_list:[Int]) -> [Int] {
    let delSet = Set(delete_list)
    return arr.filter { !delSet.contains($0) }
}