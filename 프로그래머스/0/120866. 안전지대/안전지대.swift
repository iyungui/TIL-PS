import Foundation

func solution(_ board:[[Int]]) -> Int {
    // 지뢰 -> 인접한 칸(상하좌우,대각선)도 1로 표시
    // 0인 지역 count
    let moves = [
        (-1, 0), (1, 0), (0, -1), (0, 1),
        (-1, -1), (-1, 1), (1, -1), (1, 1)
        ]
    var board = board
    let n = board.count
    var dangerZone = board
    for i in 0..<n {
        for j in 0..<n {
            if board[i][j] == 1 {
                for move in moves {
                    let ni = i + move.0
                    let nj = j + move.1
                    if ni < n && ni >= 0 && nj < n && nj >= 0 {
                        dangerZone[ni][nj] = 1
                    }
                }
            }
        }
    }
    return dangerZone.map { $0.filter { $0 == 0 }.count }.reduce(0, +)
}