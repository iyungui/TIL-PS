import Foundation

func solution(_ survey:[String], _ choices:[Int]) -> String {
    var score: [Character: Int] = [
        "R": 0, "T": 0,
        "C": 0, "F": 0,
        "J": 0, "M": 0,
        "A": 0, "N": 0
    ]
    
    for (choice, sur) in zip(choices, survey) {
        if choice == 4 { continue }
        if choice < 4 {
            score[sur.first!]! += (4 - choice)
        } else {
            score[sur.last!]! += (choice - 4)
        }
    }
    var ret = ""
    
    ret += score["R"]! >= score["T"]! ? "R" : "T"
    ret += score["C"]! >= score["F"]! ? "C" : "F"
    ret += score["J"]! >= score["M"]! ? "J" : "M"
    ret += score["A"]! >= score["N"]! ? "A" : "N"
    
    return ret
}