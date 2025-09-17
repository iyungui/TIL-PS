import Foundation

func solution(_ survey:[String], _ choices:[Int]) -> String {
    let survey = survey.map { Array($0) }
    var score = [Character: Int]()
    let types: [Character] = ["R", "T", "C", "F", "J", "M", "A", "N"]
    
    for type in types {
        score[type] = 0
    }
    
    for (idx, s) in survey.enumerated() {
        let choice = choices[idx]
        if choice < 4 {
            score[s[0]]! += 4 - choice 
        } else if choice > 4 {
            score[s[1]]! += choice - 4
        }
    }
    
    var result = ""
    result += score["R"]! >= score["T"]! ? "R" : "T"
    result += score["C"]! >= score["F"]! ? "C" : "F"
    result += score["J"]! >= score["M"]! ? "J" : "M"
    result += score["A"]! >= score["N"]! ? "A" : "N"
    return result
}