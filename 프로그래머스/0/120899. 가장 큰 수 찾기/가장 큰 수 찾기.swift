import Foundation

func solution(_ array:[Int]) -> [Int] {
    let mx = array.enumerated().max(by: { $0.element < $1.element })!
    return [mx.element, mx.offset]
}