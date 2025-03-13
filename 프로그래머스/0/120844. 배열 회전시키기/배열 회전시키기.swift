import Foundation

func solution(_ numbers:[Int], _ direction:String) -> [Int] {
    // S1
    var result = numbers
    if direction == "right" {
        let lastElement = result.removeLast()
        result.insert(lastElement, at: 0)  // [lastElement] + result
    } else {
        let firstElement = result.removeFirst()
        result.append(firstElement)
    }
    
    return result
    
    // S2
    // if direction == "right" {
    //     return [numbers.last!] + numbers.dropLast()
    // } else {
    //     return Array(numbers.dropFirst()) + [numbers.first!]
    // }
    
    
}