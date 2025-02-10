import Foundation

func solution(_ arr:[Int], _ n:Int) -> [Int] {
    // S1
    return arr.enumerated().map { (index, value) in
        let isOddLength = arr.count % 2 == 1
        return (isOddLength && index % 2 == 0) || (!isOddLength && index % 2 == 1) ? value + n : value
    }
}