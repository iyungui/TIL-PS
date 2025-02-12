import Foundation

func solution(_ num_list:[Int]) -> Int {
    var odd: String = ""
    var even: String = ""
    for num in num_list {
        if(num % 2 == 0) {
            even.append(String(num))
        } else {
            odd.append(String(num))
        }
    }
    return Int(odd)! + Int(even)!
}