import Foundation

func solution(_ num_list:[Int], _ n:Int) -> [Int] {
    // return num_list[0..<n].map { $0 }
    // return Array(num_list.prefix(n))     // 왜 Array 로 묶어야 하는지?
    return Array(num_list[0..<n])
}