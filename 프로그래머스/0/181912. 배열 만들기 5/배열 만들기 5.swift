import Foundation

func solution(_ intStrs:[String], _ k:Int, _ s:Int, _ l:Int) -> [Int] {
    return intStrs.map { Int($0.prefix(s + l).suffix(l))! }.filter { $0 > k }
}