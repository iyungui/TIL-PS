import Foundation

func solution(_ array:[Int], _ n:Int) -> Int {
    return array.min(by: { (abs($0 - n), $0) < (abs($1 - n), $1) })!
    // var diff = Int.max, answer = 0
    // array.forEach {
    //     if diff > abs($0 - n) {
    //         diff = abs($0 - n)
    //         answer = $0
    //     } else if diff == abs($0 - n) && answer > $0 {
    //         answer = $0
    //     }
    // }
    // return answer
}