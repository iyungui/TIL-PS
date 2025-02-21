import Foundation

func solution(_ a:Int, _ b:Int, _ c:Int) -> Int {
    let sum = a + b + c
    let square = a*a + b*b + c*c
    let cube = a*a*a + b*b*b + c*c*c
    switch Set([a, b, c]).count {
        case 1: return sum * square * cube
        case 2: return sum * square
        default: return sum
    }
}