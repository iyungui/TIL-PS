import Foundation

func solution(_ array:[Int]) -> [Int] {
    var mx = 0, idx = 0
    array.enumerated().forEach {
        if mx < $0.element {
            mx = $0.element
            idx = $0.offset
        }
    }
    return [mx, idx]
}