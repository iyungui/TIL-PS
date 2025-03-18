import Foundation

func solution(_ spell:[String], _ dic:[String]) -> Int {
    var spell = spell.sorted()
    for d in dic {
        if d.count != spell.joined().count { continue }
        let sortedD = d.sorted()
        var flag: Bool = true
        for j in (0..<sortedD.count) {
            if String(spell[j]) != String(sortedD[j]) { flag = false }
        }
        if flag { return 1 }
    }
    return 2
}