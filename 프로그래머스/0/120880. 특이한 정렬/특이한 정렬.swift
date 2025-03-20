import Foundation

func solution(_ numlist:[Int], _ n:Int) -> [Int] {
    return numlist
            .map { (abs($0 - n), $0) }
            .sorted { ($0.0, $1.1) < ($1.0, $0.1) }
            .map { $0.1 }
}