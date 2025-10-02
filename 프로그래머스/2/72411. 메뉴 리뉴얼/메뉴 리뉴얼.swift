import Foundation

var combi: [String] = []

func combination(_ order: [Character], _ r: Int, _ start: Int, _ cur: String) {
    if cur.count == r {
        combi.append(cur)
        return
    }
    for i in start..<order.count {
        combination(order, r, i + 1, cur + String(order[i]))
    }
}

func solution(_ orders:[String], _ course:[Int]) -> [String] {
    var combiCount: [String: Int] = [:]
    for order in orders {
        let sortedOrder = Array(order.sorted())
        for r in course {
            // r개를 뽑는 조합 만들기
            combi = []
            combination(sortedOrder, r, 0, "")
            
            for com in combi {
                combiCount[com, default: 0] += 1
            }
        }
    }
    combiCount = combiCount.filter { $0.value >= 2 }
    var result = [String]()
    for r in course {
        let sameSizeCombi = combiCount.filter { $0.key.count == r }
        guard let maxCount = sameSizeCombi.values.max() else { continue }
        for (menu, count) in sameSizeCombi {
            if count == maxCount {
                result.append(menu)
            }
        }
        
    }
    
    return result.sorted()
}