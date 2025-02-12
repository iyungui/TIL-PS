import Foundation

func solution(_ num_list:[Int]) -> Int {
    // var odd: String = ""
    // var even: String = ""
    // for num in num_list {
    //     if(num % 2 == 0) {
    //         even.append(String(num))
    //     } else {
    //         odd.append(String(num))
    //     }
    // }
    // return Int(odd)! + Int(even)!
    
    let odd = Int(num_list.filter { $0 % 2 == 1 }.map(String.init).joined())!
    let even = Int(num_list.filter { $0 % 2 == 0 }.map(String.init).joined())!
    return odd + even
}