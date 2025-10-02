import Foundation

func solution(_ board: [[Int]]) -> Int {
    let n = board.count
    let dy = [-1, 0, 1, 0]
    let dx = [0, 1, 0, -1]

    // cost[y][x][dir]: (y, x) 위치에 dir 방향으로 도착했을 때의 최소 비용
    var cost = Array(repeating: Array(repeating: Array(repeating: Int.max, count: 4), count: n), count: n)

    // (curY, curX, curDir, curCost)
    var queue: [(Int, Int, Int, Int)] = []

    if n > 1 {
        if board[0][1] == 0 {
            // 위치(0, 1), 오른쪽(1), 비용 100
            queue.append((0, 1, 1, 100))
            cost[0][1][1] = 100
        }
        if board[1][0] == 0 {
            // 위치(1, 0), 아래쪽(2), 비용 100
            queue.append((1, 0, 2, 100))
            cost[1][0][2] = 100
        }
    }

    var queueIndex = 0

    while queueIndex < queue.count {
        let (y, x, dir, curCost) = queue[queueIndex]
        queueIndex += 1

        // 이미 더 저렴한 경로가 있으면 스킵
        if curCost > cost[y][x][dir] {
            continue
        } 

        for nextDir in 0..<4 {
            let ny = y + dy[nextDir]
            let nx = x + dx[nextDir]

            // 범위 체크, 벽 체크
            if ny < 0 || ny >= n || nx < 0 || nx >= n || board[ny][nx] == 1 {
                continue
            }

            // 새로운 비용 계산
            let newCost = curCost + (dir != nextDir ? 600 : 100)

            // 더 저렴한 경로를 찾았으면 업데이트
            if newCost < cost[ny][nx][nextDir] {
                cost[ny][nx][nextDir] = newCost
                queue.append((ny, nx, nextDir, newCost))
            }
        }
    }

    // 도착점에서 4방향 중 최소 비용 찾기
    let ret = cost[n-1][n-1].min() ?? 0

    return ret
}