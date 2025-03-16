import Foundation

func solution(_ s:String) -> String {
    var counts = Dictionary<Character, Int>()
    var answer = ""
    for c in s {
        counts[c, default: 0] += 1
    }
    return counts.filter { $0.value == 1 }.keys.sorted().reduce("") { $0 + String($1) }
    // for c in counts {
    //     if c.value == 1 {
    //         answer += String(c.key)
    //     }
    // }
    // return String(answer.sorted())
}