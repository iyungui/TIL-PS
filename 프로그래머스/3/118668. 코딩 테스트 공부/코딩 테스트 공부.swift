import Foundation

// 초기 alp, cop 에서 목표 alp, cop까지 가는 최단거리를 구하는 문제
// dp 문제
func solution(_ alp: Int, _ cop: Int, _ problems: [[Int]]) -> Int {
    // 목표 알고력과 코딩력을 구함 (모든 문제의 요구사항 중 최대값)
    var maxAlp = alp
    var maxCop = cop

    for problem in problems {
        let alpReq = problem[0]
        let copReq = problem[1]

        maxAlp = max(maxAlp, alpReq)
        maxCop = max(maxCop, copReq)
    }

    // DP 배열 초기화
    // dp[i][j] = (알고력 i, 코딩력 j) 상태에 도달하는데 필요한 최단 시간
    var dp = Array(repeating: Array(repeating: 10000, count: maxCop + 1), count: maxAlp + 1)

    // 기저 사례: 초기상태는 시간 0
    dp[alp][cop] = 0

    // DP 배열 업데이트
    for i in alp...maxAlp {
        for j in cop...maxCop {
            if dp[i][j] == Int.max { continue }

            // 1. 알고력을 공부하는 경우 (알고력 1 증가, 시간 1 소요)
            if i + 1 <= maxAlp {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1)
            }

            // 2. 코딩력을 공부하는 경우 (코딩력 1 증가, 시간 1 소요)
            if j + 1 <= maxCop {
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1)
            }

            // 3. 문제 풀기
            for problem in problems {
                let alpReq = problem[0]
                let copReq = problem[1]
                let alpRwd = problem[2]
                let copRwd = problem[3]
                let cost = problem[4]

                // 현재 상태(i, j)에서 이 문제를 풀 수 있는지 확인
                if i >= alpReq && j >= copReq {
                    // 목표를 넘지 않도록 제한
                    let nextAlp = min(i + alpRwd, maxAlp)
                    let nextCop = min(j + copRwd, maxCop)

                    dp[nextAlp][nextCop] = min(dp[nextAlp][nextCop], dp[i][j] + cost)
                }
            }
        }
    }

    return dp[maxAlp][maxCop]
}