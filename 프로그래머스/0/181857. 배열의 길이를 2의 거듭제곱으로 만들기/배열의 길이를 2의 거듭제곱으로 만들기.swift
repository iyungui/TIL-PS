import Foundation

func solution(_ arr:[Int]) -> [Int] {
    var length = arr.count
    var powerOfTwo = 1
    
    while powerOfTwo < length {
        powerOfTwo *= 2
    }
    if powerOfTwo == length {
        return arr
    }
    
    var result: [Int] = arr
    result.append(contentsOf: repeatElement(0, count: powerOfTwo - length))
    return result
}