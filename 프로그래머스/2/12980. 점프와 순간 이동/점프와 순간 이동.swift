import Foundation

func solution(_ n:Int) -> Int {
    if n == 1 { return 1 }
    if n % 2 == 0 { return solution(n / 2) }
    return solution(n / 2) + 1
}