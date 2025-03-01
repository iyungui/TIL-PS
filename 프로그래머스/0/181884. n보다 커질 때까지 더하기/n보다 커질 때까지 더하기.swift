import Foundation

func solution(_ numbers:[Int], _ n:Int) -> Int {
    // var sum = 0
    // numbers.forEach {
    //     if sum <= n { sum += $0 }
    // }
    // return sum
    
    // for num in numbers where sum <= n {
    //     sum += num
    // }
    // return sum
    
    // return numbers.reduce(0) {
    //     if $0 <= n { return $0 + $1 }
    //     return $0
    // }
    
    return numbers.reduce(0) { $0 > n ? $0 : $0 + $1 }
}