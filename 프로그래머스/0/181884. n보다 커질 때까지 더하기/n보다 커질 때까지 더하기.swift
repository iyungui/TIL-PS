import Foundation

func solution(_ numbers:[Int], _ n:Int) -> Int {
    // 오답
    // var sum : Int = 0
    // numbers.map {
    //     sum += $0
    //     if(sum > n) {
    //         break
    //     }
    // }
    // return sum
    
    // S1 for + if
    // var sum = 0
    // for num in numbers {
    //     sum += num
    //     if sum > n { break }
    // }
    // return sum
    
    // S2 for + where
    // var sum = 0
    // for num in numbers where sum <= n { sum += num }
    // return sum

    // S3 forEach
    // var sum = 0
    // numbers.forEach { (num: Int) -> Void in
    //     if(sum <= n) {
    //         sum += num
    //     } 
    // }
    // return sum
    
    // S4 reduce (축약)   // best
    return numbers.reduce(0) { $0 > n ? $0 : $0 + $1 }
    
    // S4 reduce (풀코드) 
    // return numbers.reduce(0, { (result: Int, element: Int) -> Int in
    //     result > n ? result : result + element
    // })
    
}
/*
map을 사용하면 안 되는 이유:

map은 변환을 위한 함수 (각 요소를 다른 것으로 변환)
중간에 중단할 수 없음 (break 안됨)
부수 효과(side effect)를 위한 용도가 아님

이 문제는 단순 순회가 목적이므로 for 문이나 forEach가 더 적절합니다.
*/