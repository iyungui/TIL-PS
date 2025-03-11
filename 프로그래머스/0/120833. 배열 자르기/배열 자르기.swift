import Foundation

func solution(_ numbers:[Int], _ num1:Int, _ num2:Int) -> [Int] {
    var a: [Int] = []
    for i in (num1...num2) {
        a.append(numbers[i])
    }
    return a
}