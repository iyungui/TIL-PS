import Foundation

func solution(_ array:[Int]) -> Int {
    let array = array.sorted()
    return array[array.count / 2]
}