import Foundation

func solution(_ N:Int, _ stages:[Int]) -> [Int] {
    var stages = stages.sorted()
    var ret = [(Int, Double)]()
    var start = 0
    
    for i in 1...N {
        if let index = stages.lastIndex(of: i) {
            let cnt = index - start + 1
            let remain = stages.count - start
            let rate = Double(cnt) / Double(remain)
            start = (index + 1)
            ret.append((i, rate))
        }
        else {
            if start <= stages.count {
                ret.append((i, 0))
            } else {
                ret.append((i, 1))
            }
        }
    }
    return ret.sorted { $0.1 == $1.1 ? $0.0 < $1.0 : $0.1 > $1.1 }.map { $0.0 }
}