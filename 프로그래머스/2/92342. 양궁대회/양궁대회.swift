import Foundation

func solution(_ n: Int, _ info: [Int]) -> [Int] {
    var maxDiff = -1
    var bestAnswer: [Int] = []

    func dfs(_ score: Int, _ remainArrows: Int, _ ryanShots: [Int]) {
        // 0점까지 모든 점수를 고려했을 때
        if score < 0 {
            // 남은 화살이 있다면 0점에 모두 쏘기
            var finalShots = ryanShots
            if remainArrows > 0 { finalShots[10] = remainArrows }
            let diff = calculateDiff(info, finalShots)
            // 라이언이 이기는 경우
            if diff > 0 {
                if diff > maxDiff {
                    maxDiff = diff
                    bestAnswer = finalShots
                } else if diff == maxDiff {
                    // 이전과 똑같은 점수 차이인 경우, 낮은 점수를 더 많이 맞힌 경우를 선택
                    if isLowerScore(finalShots, bestAnswer) {
                        bestAnswer = finalShots
                    }
                }
            }
            return
        }
        
        let apeachArrows = info[score]
        
        // 1. 현재 점수를 포기하고 0발 쏘는 경우
        dfs(score - 1, remainArrows, ryanShots)

        // 2. 현재 점수 가져가기 위해 어피치보다 1발 더 쏘는 경우
        let needArrows = apeachArrows + 1
        if remainArrows >= needArrows {
            var newShots = ryanShots
            newShots[score] = needArrows
            dfs(score - 1, remainArrows - needArrows, newShots)
        }
    }

    func calculateDiff(_ apeachShots: [Int], _ ryanShots: [Int]) -> Int {
        var apeachScore = 0
        var ryanScore = 0

        for i in 0...10 {
            let score = 10 - i
            if apeachShots[i] + ryanShots[i] == 0 { continue }
            else if ryanShots[i] > apeachShots[i] { ryanScore += score }
            else { apeachScore += score }
        }

        return ryanScore - apeachScore
    }

    func isLowerScore(_ currentShots: [Int], _ bestShots: [Int]) -> Bool {
        for i in (0...10).reversed() {
            if currentShots[i] != bestShots[i] {
                return currentShots[i] > bestShots[i]
            }
        }
        return false
    }
    dfs(10, n, Array(repeating: 0, count: 11))

    return maxDiff > 0 ? bestAnswer : [-1]
}