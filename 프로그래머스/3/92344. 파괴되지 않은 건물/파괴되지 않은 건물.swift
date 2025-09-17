
func solution(_ board: [[Int]], _ skill: [[Int]]) -> Int {
    let n = board.count
    let m = board[0].count

    // n + 1, m + 1로 누적합 배열 초기화
    var psum = Array(repeating: Array(repeating: 0, count: m + 1), count: n + 1)

    for s in skill {
        let type = s[0]
        let r1 = s[1], c1 = s[2], r2 = s[3], c2 = s[4]
        let degree = s[5]

        let value = type == 1 ? -degree : degree

        psum[r1][c1] += value
        psum[r1][c2 + 1] -= value
        psum[r2 + 1][c1] -= value
        psum[r2 + 1][c2 + 1] += value
    }

    // 행 방향 누적합 (왼쪽에서 오른쪽으로)
    for i in 0..<n {
        for j in 1..<m {
            psum[i][j] += psum[i][j - 1]
        }
    }

    // 열 방향 누적합 (위에서 아래로)
    for i in 1..<n {
        for j in 0..<m {
            psum[i][j] += psum[i - 1][j]
        }
    }

    // 원래 board + 누적합 > 0
    var result = 0
    for i in 0..<n {
        for j in 0..<m {
            if board[i][j] + psum[i][j] > 0 { result += 1 }
        }
    }
    return result
}