import Foundation

func solution(_ n:Int, _ k:Int) -> [Int] {
    (1...n).filter{ $0 % k == 0 }
}