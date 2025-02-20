import Foundation

func solution(_ binomial: String) -> Int {
    let parts = binomial.split(separator: " ")
    let a = Int(parts[0])!
    let op = parts[1]
    let b = Int(parts[2])!
    
    switch op {
        case "+": return a + b
        case "-": return a - b
        case "*": return a * b
        default: return 0
    }
}