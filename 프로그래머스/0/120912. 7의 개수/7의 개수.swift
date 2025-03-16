import Foundation

func solution(_ array:[Int]) -> Int {
    var sum = 0
    let a = array.map { String($0) }
    a
    .forEach {
        $0.forEach {
            if String($0) == "7" { sum += 1 }
        }
    }
    
    return sum
}