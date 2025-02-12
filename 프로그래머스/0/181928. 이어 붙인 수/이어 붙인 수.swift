import Foundation

func solution(_ num_list:[Int]) -> Int {
    let odd = Int(num_list.filter { $0 % 2 == 1 }.map(String.init).joined())!
    let even = Int(num_list.filter { $0 % 2 == 0 }.map(String.init).joined())!
    return odd + even
}