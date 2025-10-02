import Foundation

func solution(_ board:[[Int]]) -> Int {
    let n = board.count
    let dy = [-1, 0, 1, 0]
    let dx = [0, 1, 0, -1]
    var cost = Array(repeating: Array(repeating: Array(repeating: Int.max, count: 4), count: n), count: n)
    
    // y, x, dir, cost
    var queue: [(Int, Int, Int, Int)] = [(0, 0, 0, 0)]
    var queueIndex = 0
    
    if board[0][1] == 0 {
        queue.append((0, 1, 1, 100))
        cost[0][1][1] = 100
    }
    if board[1][0] == 0 {
        queue.append((1, 0, 2, 100))
        cost[1][0][2] = 100
    }
    
    while queueIndex < queue.count {
        let cur = queue[queueIndex]
        let (y, x, dir, curCost) = (cur.0, cur.1, cur.2, cur.3)
        queueIndex += 1
        if curCost > cost[y][x][dir] { continue }
        
        for nextDir in 0..<4 {
            let ny = y + dy[nextDir]
            let nx = x + dx[nextDir]
            
            if ny < 0 || ny >= n || nx < 0 || nx >= n || board[ny][nx] == 1 { continue }
            
            let newCost = curCost + (dir != nextDir ? 600 : 100)
            
            if newCost < cost[ny][nx][nextDir] {
                cost[ny][nx][nextDir] = newCost
                queue.append((ny, nx, nextDir, newCost))
            }
        }
        
    }
    
    return cost[n - 1][n - 1].min()!
}