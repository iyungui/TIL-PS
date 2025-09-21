import Foundation

// alp, cop 에서 maxAlp, maxCop 로 가는 최단 시간 구하는 문제.
// dp로 풀 수 있음
func solution(_ alp:Int, _ cop:Int, _ problems:[[Int]]) -> Int {
    var maxAlp = alp
    var maxCop = cop
    problems.forEach {
        maxAlp = max($0[0], maxAlp)
        maxCop = max($0[1], maxCop)
    }
    var dp = Array(repeating: Array(repeating: 10000, count: maxCop + 1), count: maxAlp + 1)
    dp[alp][cop] = 0
    for curAlp in alp...maxAlp {
        for curCop in cop...maxCop {
            var minAlp = min(maxAlp, curAlp + 1)
            var minCop = min(maxCop, curCop + 1)
            
            dp[minAlp][curCop] = min(dp[minAlp][curCop], dp[curAlp][curCop] + 1)
            dp[curAlp][minCop] = min(dp[curAlp][minCop], dp[curAlp][curCop] + 1)
            
            problems.forEach {
                minAlp = min(maxAlp, curAlp + $0[2])
                minCop = min(maxCop, curCop + $0[3])
                if curAlp >= $0[0] && curCop >= $0[1] {
                    dp[minAlp][minCop] = min(dp[minAlp][minCop], dp[curAlp][curCop] + $0[4])
                }
            }
        }
    }
    return dp[maxAlp][maxCop]
}