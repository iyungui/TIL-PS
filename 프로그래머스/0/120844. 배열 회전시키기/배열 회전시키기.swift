import Foundation

func solution(_ numbers:[Int], _ direction:String) -> [Int] {
    var result = numbers
    if direction == "right" {
        let lastElement = result.removeLast()
        result.insert(lastElement, at: 0)
    } else {
        let firstElement = result.removeFirst()
        result.append(firstElement)
    }
    return result
}