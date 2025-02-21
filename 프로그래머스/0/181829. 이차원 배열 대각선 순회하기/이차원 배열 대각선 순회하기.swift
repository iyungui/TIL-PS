import Foundation

func solution(_ board:[[Int]], _ k:Int) -> Int {
    var ret: Int = 0
    for i in 0..<board.count {
        for j in 0..<board[i].count where i + j <= k {
            ret += board[i][j]
        }
    }
    return ret
}