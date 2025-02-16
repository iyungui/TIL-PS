import Foundation

func solution(_ n:Int, _ k:Int) -> [Int] {
    (k...n).filter{ $0 % k == 0 }
}