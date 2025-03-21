import Foundation

func solution(_ quiz:[String]) -> [String] {
    let quizArr = quiz.map { $0.components(separatedBy: " ") }
    var result: [String] = []
    for arr in quizArr {
        if arr[1] == "-" {
            if Int(arr[0])! - Int(arr[2])! == Int(arr[4])! { result.append("O") }
            else { result.append("X") }
        } else {
            if Int(arr[0])! + Int(arr[2])! == Int(arr[4])! { result.append("O") }
            else { result.append("X") }
        }
    }
    return result
}