import Foundation

func solution(_ n:Int) -> Int {
    stride(from: 2, through: n, by: 2).reduce(0, +)
}