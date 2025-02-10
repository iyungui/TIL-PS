import Foundation

func solution(_ arr:[Int], _ n:Int) -> [Int] {
//     S1 (함수형)
//     return arr.enumerated().map { (index, value) in
//         let isOddLength = arr.count % 2 == 1
//         return (isOddLength && index % 2 == 0) || (!isOddLength && index % 2 == 1) ? value + n : value
//     }
    
//     S2 (명령형)
    var result = arr
    let isOddLength = arr.count % 2 == 1
    
    for i in arr.indices {
        if (isOddLength && i % 2 == 0) || (!isOddLength && i % 2 == 1) {
            result[i] += n
        }
    }
    return result
}