import Foundation

func solution(_ num_list:[Int]) -> Int {
    let odd: String = num_list.filter { $0 % 2 == 1 }.reduce("") {
        String($0) + String($1)
    }
    let even: String = num_list.filter { $0 % 2 == 0 }.reduce("") {
        String($0) + String($1)
    }
    return Int(odd)! + Int(even)!
}