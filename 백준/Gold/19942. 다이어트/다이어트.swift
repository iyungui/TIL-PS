import Foundation

struct Ingredient {
    let protein: Int
    let fat: Int
    let carb: Int
    let vitamin: Int
    let cost: Int
}

let INF = 987654321
var n = 0, mp = 0, mf = 0, ms = 0, mv = 0
var p = 0, f = 0, c = 0, v = 0, minCost = INF, totalCost = 0
var ingredients: [Ingredient] = []
var resultMap: [Int: [[Int]]] = [:]

// stdin에서 입력 받기
if let nStr = readLine(), let nVal = Int(nStr) {
    n = nVal
}

if let nutrientStr = readLine(), let nutrients = nutrientStr.split(separator: " ").map({ Int($0) }) as? [Int], nutrients.count == 4 {
    mp = nutrients[0]
    mf = nutrients[1]
    ms = nutrients[2]
    mv = nutrients[3]
}

for _ in 0..<n {
    if let ingredientStr = readLine(), let vals = ingredientStr.split(separator: " ").map({ Int($0) }) as? [Int], vals.count == 5 {
        ingredients.append(Ingredient(protein: vals[0], fat: vals[1], carb: vals[2], vitamin: vals[3], cost: vals[4]))
    }
}

// 비트마스킹으로 모든 조합 탐색
for i in 1..<(1 << n) {
    p = 0
    f = 0
    c = 0
    v = 0
    totalCost = 0
    var selected: [Int] = []
    
    for j in 0..<n {
        if (i & (1 << j)) != 0 {
            selected.append(j + 1)
            p += ingredients[j].protein
            f += ingredients[j].fat
            c += ingredients[j].carb
            v += ingredients[j].vitamin
            totalCost += ingredients[j].cost
        }
    }
    
    if p >= mp && f >= mf && c >= ms && v >= mv {
        if minCost >= totalCost {
            minCost = totalCost
            if resultMap[minCost] == nil {
                resultMap[minCost] = []
            }
            resultMap[minCost]!.append(selected)
        }
    }
}

if minCost == INF {
    print("-1")
} else {
    print(minCost)
    // 사전순으로 정렬
    resultMap[minCost]!.sort { lhs, rhs in
        for (l, r) in zip(lhs, rhs) {
            if l != r {
                return l < r
            }
        }
        return lhs.count < rhs.count
    }
    
    print(resultMap[minCost]![0].map { String($0) }.joined(separator: " "))
}