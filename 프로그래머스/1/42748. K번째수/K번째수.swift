import Foundation

func solution(_ array:[Int], _ commands:[[Int]]) -> [Int] {
    var res: [Int] = []
    for com in commands {
        let subArr = Array(array[(com[0] - 1)..<com[1]]).sorted()
        res.append(subArr[com[2] - 1])
    }
    return res
}