
import Foundation

struct State: Hashable {
    let redY: Int
    let redX: Int
    let blueY: Int
    let blueX: Int
    let count: Int
}

let input = readLine()!.components(separatedBy: " ").map { Int($0)! }
let n = input[0], m = input[1]

var board: [[Character]] = []
var redStart = (0, 0)
var blueStart = (0, 0)
var hole = (0, 0)

for i in 0..<n {
    let line = Array(readLine()!)
    board.append(line)
    
    for j in 0..<m {
        if board[i][j] == "R" {
            redStart = (i, j)
            board[i][j] = "."
        } else if board[i][j] == "B" {
            blueStart = (i, j)
            board[i][j] = "."
        } else if board[i][j] == "O" {
            hole = (i, j)
        }
    }
}

// 상 하 좌 우
let dy = [-1, 1, 0, 0]
let dx = [0, 0, -1, 1]


func bfs() -> Int {
    var queue: [State] = [State(redY: redStart.0, redX: redStart.1, blueY: blueStart.0, blueX: blueStart.1, count: 0)]
    var visited = Set<State>()
    
    visited.insert(queue.first!)
    
    var index = 0
    while index < queue.count {
        let curr: State = queue[index]
        index += 1
        
        if curr.count >= 10 { continue }
        
        for i in 0..<4 {
            var ry = curr.redY, rx = curr.redX, by = curr.blueY, bx = curr.blueX
            var redHole = false, blueHole = false
            
            let moveRed = { () -> Void in
                while true {
                    let nry = ry + dy[i], nrx = rx + dx[i]
                    
                    if board[nry][nrx] == "#" || (!blueHole && nry == by && nrx == bx) { break }
                    if board[nry][nrx] == "O" {
                        redHole = true
                        ry = -1; rx = -1
                    }
                    
                    ry = nry; rx = nrx
                }
            }
            
            let moveBlue = { () -> Void in
                while true {
                    let nby = by + dy[i], nbx = bx + dx[i]
                    
                    if board[nby][nbx] == "#" || (!redHole && nby == ry && nbx == rx )  { break }
                    if board[nby][nbx] == "O" {
                        blueHole = true
                        by = -1; bx = -1
                    }
                    
                    by = nby; bx = nbx
                }
            }
            
            switch i {
            case 0: // 위로 기울이기
                if ry < by { moveRed(); moveBlue() }
                else { moveBlue(); moveRed() }
            case 1: // 아래로 기울이기
                if ry > by { moveRed(); moveBlue() }
                else { moveBlue(); moveRed() }
            case 2: // 왼쪽으로 기울이기
                if rx < bx { moveRed(); moveBlue() }
                else { moveBlue(); moveRed() }
            case 3: // 오른쪽으로 기울이기
                if rx > bx { moveRed(); moveBlue() }
                else { moveBlue(); moveRed() }
            default: break
            }
            
            // 파란 구슬이 빠졌다면, 실패이므로 해당 방향 그 이후로 탐색하지 않음. (queue에 담지 않음)
            if blueHole { continue }
            
            // 빨간 구슬만 구멍에 빠졌다면 성공이므로
            if redHole {
                return curr.count + 1
            }
            
            // 구슬이 모두 이동이 없었다면 다음 방향으로 (그 이후로 탐색하지 않음. (queue에 담지 않음))
            if ry == curr.redY && rx == curr.redX && by == curr.blueY && bx == curr.blueX { continue }
            
            let nextState = State(redY: ry, redX: rx, blueY: by, blueX: bx, count: curr.count + 1)
            
            // 방문하지 않은 상태라면 큐에 추가
            if !visited.contains(nextState) {
                queue.append(nextState)
                visited.insert(nextState)
            }
        }
    }
    return -1
}

print(bfs())