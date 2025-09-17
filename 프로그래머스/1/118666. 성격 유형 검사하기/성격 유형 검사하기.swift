import Foundation

func solution(_ survey:[String], _ choices:[Int]) -> String {
    var result = ""
    // 각 성격유형의 점수를 0으로 초기화
    var score: [Character: Int] = [
        "R": 0, "T": 0,
        "C": 0, "F": 0,
        "J": 0, "M": 0,
        "A": 0, "N": 0
    ]
    for (sur, choice) in zip(survey, choices) {
        if choice == 4 { continue }
        
        if choice < 4 {
            score[sur.first!]! += 4 - choice
        } else {
            score[sur.last!]! += choice - 4
        }
    }
    result += score["R"]! >= score["T"]! ? "R" : "T"
    result += score["C"]! >= score["F"]! ? "C" : "F"
    result += score["J"]! >= score["M"]! ? "J" : "M"
    result += score["A"]! >= score["N"]! ? "A" : "N"
    return result
}