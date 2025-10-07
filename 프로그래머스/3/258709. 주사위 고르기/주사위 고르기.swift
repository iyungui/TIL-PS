import Foundation

func solution(_ dice:[[Int]]) -> [Int] {
    let n = dice.count
    // A가 몇번째 주사위들을 n / 2개 뽑을지 조합 구하기
    let aCombi = combi(n, n / 2)
    var aMaxWinCount = 0
    var ret = [Int]()
    
    for aDiceIndices in aCombi {
        let bDiceIndices = (0..<n).filter { !aDiceIndices.contains($0) }
        
        let aWinCount: Int = calc(
            aDices: aDiceIndices.map { dice[$0] },
            bDices: bDiceIndices.map { dice[$0] }
        )
        
        if aMaxWinCount < aWinCount {
            aMaxWinCount = aWinCount
            ret = aDiceIndices
        }
    }
    
    return ret.sorted().map { $0 + 1 }
}

func combi(_ diceIndices: Int, _ k: Int) -> [[Int]] {
    var ret = [[Int]]()
    
    func backtrack(_ start: Int, _ cur: [Int]) {
        if cur.count == k {
            ret.append(cur)
            return
        }
        
        for i in start..<diceIndices {
            backtrack(i + 1, cur + [i])
        }
    }
    
    backtrack(0, [])
    return ret
}

func calc(aDices: [[Int]], bDices: [[Int]]) -> Int {
    let aSums: [Int] = getPossibleSums(aDices)
    let bSums: [Int] = getPossibleSums(bDices).sorted()
    
    var ret = 0
    
    func binarySearchCount(target: Int) -> Int {
        var left = 0
        var right = bSums.count
        
        while left < right {
            let mid = (left + right) / 2
            if bSums[mid] < target {
                left = mid + 1
            }
            else {
                right = mid
            }
        }
        return left
    }
    
    for aSum in aSums {
        ret += binarySearchCount(target: aSum)
    }
    
    return ret
}

func getPossibleSums(_ dices: [[Int]]) -> [Int] {
    var sums = [0]
    for dice in dices {
        var newSums = [Int]()
        for sum in sums {
            for face in dice {
                newSums.append(sum + face)
            }
        }
        sums = newSums
    }
    return sums
}

