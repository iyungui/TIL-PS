import Foundation

func solution(_ N:Int, _ stages:[Int]) -> [Int] {
    var rates = [Int: Double]()
    let stages = stages.sorted()
    var start = 0
    for i in 1...N {
        if let index = stages.lastIndex(of: i) {
            let cnt = index - start + 1
            let remain = stages.count - start
            let rate = Double(cnt) / Double(remain)
            start = index + 1
            rates[i] = rate
        }
        else {
            if start <= stages.count {
                rates[i] = 0
            } else {
                rates[i] = 1
            }
        }
    }
    
    return rates
            .sorted { ($0.value == $1.value) ? ($0.key < $1.key) : ($0.value > $1.value) }
            .map { Int($0.key) }
}