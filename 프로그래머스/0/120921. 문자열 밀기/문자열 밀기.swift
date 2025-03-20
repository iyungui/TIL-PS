import Foundation

func solution(_ A:String, _ B:String) -> Int {
    var count = 0, a = A
    while count < A.count {
        if a == B { return count }
        a = String(a.last!) + String(a.dropLast())
        count += 1
    }
    return -1
}