import Foundation

var combi = [String]()

func combination(_ order: [Character], _ start: Int, _ k: Int, _ cur: String) {
    if cur.count == k {
        combi.append(cur)
        return
    }
    for i in start..<order.count {
        combination(order, i + 1, k, cur + String(order[i]))
    }
}

func solution(_ orders:[String], _ course:[Int]) -> [String] {
    var combiDict = [String: Int]()
    for order in orders {
        let sortedOrder = Array(order).sorted()
        for r in course {
            combi = []
            combination(sortedOrder, 0, r, "")
            
            for c in combi {
                combiDict[c, default: 0] += 1
            }
        }
    }
    combiDict = combiDict.filter { $0.value >= 2 }
    var ret = [String]()
    for r in course {
        let same = combiDict.filter { $0.key.count == r }
        guard let maxCnt = same.values.max() else { continue }
        for (menu, cnt) in same {
            if cnt == maxCnt { ret.append(menu) }
        }
    }
    return ret.sorted()
}