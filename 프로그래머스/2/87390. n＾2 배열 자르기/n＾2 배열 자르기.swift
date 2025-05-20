import Foundation

func solution(_ n:Int, _ left:Int64, _ right:Int64) -> [Int] {
    var res: [Int] = []
    for i in Int(left)...Int(right) {
        let row = i / n
        let col = i % n
        let num = max(row + 1, col + 1)
        res.append(num)
    }
    
    return res
}