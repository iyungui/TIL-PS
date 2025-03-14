import Foundation

func solution(_ num_list:[Int], _ n:Int) -> [[Int]] {
    var answer: [[Int]] = []
    var a: [Int] = []
    for num in num_list {
        a.append(num)
        if a.count == n {
            answer.append(a)
            a = []
        }
    }
    return answer
}