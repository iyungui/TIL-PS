import Foundation

func solution(_ n:Int, _ lost:[Int], _ reserve:[Int]) -> Int {
    var students = Array(repeating: 1, count: n)
    for i in lost { students[i - 1] -= 1 }
    for i in reserve { students[i - 1] += 1 }
    for i in 0..<n {
        if students[i] <= 0 {
            if i > 0 && students[i - 1] > 1 {
                students[i - 1] -= 1
                students[i] += 1
            }
            else if i < n - 1 && students[i + 1] > 1 {
                students[i + 1] -= 1
                students[i] += 1
            } 
        }
    }
    return students.filter { $0 >= 1 }.count
}