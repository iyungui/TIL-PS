import Foundation

func solution(_ numbers:[Int], _ n:Int) -> Int {
    return numbers.reduce(0) { $0 > n ? $0 : $0 + $1 }
}