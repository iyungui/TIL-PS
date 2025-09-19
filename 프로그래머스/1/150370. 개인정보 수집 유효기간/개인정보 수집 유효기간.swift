import Foundation

func solution(_ today: String, _ terms: [String], _ privacies: [String]) -> [Int] {
    func dateToNumber(_ dateStr: String) -> Int {
        let com = dateStr.components(separatedBy: ".").map { Int($0)! }
        let y = com[0] - 2000
        let m = com[1] - 1
        let d = com[2] - 1
        return y * 12 * 28 + m * 28 + d
    }
    var termMap: [String: Int] = [:]
    for term in terms {
        let com = term.components(separatedBy: " ")
        termMap[com[0]] = Int(com[1])!
    }
    let today = dateToNumber(today)
    var ret: [Int] = []
    for (idx, pri) in privacies.enumerated() {
        let com = pri.components(separatedBy: " ")
        let expireDate: Int = dateToNumber(com[0]) + termMap[com[1]]! * 28
        if today >= expireDate {
            ret.append(idx + 1)
        }
    }
    return ret
}