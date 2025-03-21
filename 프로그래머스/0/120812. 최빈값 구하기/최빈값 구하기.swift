import Foundation

func solution(_ array:[Int]) -> Int {
    var dict = [Int: Int]()
    array.forEach {
        dict[$0, default: 0] += 1   // key: number, value: count
    }
    let maxFrequency = dict.values.max() ?? 0
    let mostFrequentNumbers = dict.filter { $0.value == maxFrequency }.keys
    
    return mostFrequentNumbers.count > 1 ? -1 : mostFrequentNumbers.first ?? -1
}