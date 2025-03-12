import Foundation

func solution(_ n:Int) -> [Int] {
    return Array((0...n).filter { $0 % 2 == 1 })
}