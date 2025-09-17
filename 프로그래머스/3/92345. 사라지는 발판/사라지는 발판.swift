func solution(_ board:[[Int]], _ aloc:[Int], _ bloc:[Int]) -> Int {
    let dx = [-1, 1, 0, 0]  // 상, 하, 좌, 우
    let dy = [0, 0, -1, 1]
    let n = board.count
    let m = board[0].count
    
    // (승리 여부, 이동 횟수) 반환
    func dfs(_ board: inout [[Int]], _ ax: Int, _ ay: Int, _ bx: Int, _ by: Int, _ turn: Bool) -> (Bool, Int) {

        // 현재 차례인 플레이어의 위치
        let (curX, curY) = turn ? (ax, ay) : (bx, by)
        
        // 현재 플레이어가 움직일 수 있는지 확인
        var canMove = false
        for i in 0..<4 {
            let nx = curX + dx[i]
            let ny = curY + dy[i]
            if nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] == 1 {
                canMove = true
                break
            }
        }
        
        // 움직일 수 없으면 패배
        if !canMove {
            return (false, 0)
        }
        
        // 두 플레이어가 같은 위치에 있고, 현재 플레이어가 움직일 수 있으면
        // 현재 플레이어가 움직여서 상대방이 패배하게 되므로 즉시 승리
        if ax == bx && ay == by {
            print("\(turn ? "A" : "B")가 이겼다!")
            return (true, 1)
        }
        
        var canWin = false
        var minWin = Int.max    // 승리할 때 최소 이동 횟수
        var maxLose = 0         // 패배할 때 최대 이동 횟수
        
        // 4방향으로 이동 시도
        for i in 0..<4 {
            let nx = curX + dx[i]
            let ny = curY + dy[i]
            
            if nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] == 1 {
                board[curX][curY] = 0  // 현재 발판 제거
                
                // 상대방 차례로 넘어가서 결과 확인
                let (opponentWin, opponentMoves) = turn ? 
                    dfs(&board, nx, ny, bx, by, false) : 
                    dfs(&board, ax, ay, nx, ny, true)
                
                board[curX][curY] = 1  // 발판 복구 (백트래킹)
                
                if !opponentWin {  // 상대가 패배하면 나는 승리
                    canWin = true
                    minWin = min(minWin, opponentMoves + 1)
                } else {  // 상대가 승리하면 나는 패배
                    maxLose = max(maxLose, opponentMoves + 1)
                }
            }
        }
        
        // 이길 수 있으면 최소 이동으로 승리, 질 수밖에 없으면 최대 이동으로 패배
        if canWin {
            return (true, minWin)
        } else {
            return (false, maxLose)
        }
    }
    
    var mutableBoard = board
    let result = dfs(&mutableBoard, aloc[0], aloc[1], bloc[0], bloc[1], true)
    return result.1
}