import Foundation

// 입력 처리
let input = readLine()!.components(separatedBy: " ").map { Int($0)! }
let n = input[0], m = input[1]

var board: [[Character]] = []
var redStart = (0, 0)
var blueStart = (0, 0)
var hole = (0, 0)

for i in 0..<n {
    let line = Array(readLine()!)
    board.append(line)
    
    // 빨간 구슬, 파란 구슬의 위치 저장
    for j in 0..<m {
        if line[j] == "R" {
            redStart = (i, j)
            board[i][j] = "."   // 보드에서 구슬 제거   --> ?
        } else if line[j] == "B" {
            blueStart = (i, j)
            board[i][j] = "."   // 보드에서 구슬 제거   --> ?
        } else if line[j] == "O" {
            hole = (i, j)
        }
    }
}

// 상태를 표현하는 구조체
struct State: Hashable {
    let redY: Int
    let redX: Int
    let blueY: Int
    let blueX: Int
    let count: Int
}

// 방향 정의 (상, 하, 좌, 우)
let dy = [-1, 1, 0, 0]
let dx = [0, 0, -1, 1]

// bfs 함수 구현
func bfs() -> Int {
    var queue = [State(redY: redStart.0, redX: redStart.1, blueY: blueStart.0, blueX: blueStart.1, count: 0)]
    var visited = Set<State>()  // Set 을 사용하여 방문 여부 저장 (구조체가 Hashable 해야 함)
    
    visited.insert(queue[0])
    
    var index = 0
    while index < queue.count {
        let curr = queue[index]
        index += 1
        
        // 10번을 초과하면 더 이상 진행하지 않음
        if curr.count >= 10 {
            continue
        }
        
        // 4방향으로 기울이기
        for i in 0..<4 {
            
            // 구슬 이동 시뮬레이션
            
            // 현재 구슬 위치에서 시작
            var ry = curr.redY, rx = curr.redX
            var by = curr.blueY, bx = curr.blueX
            var redHole = false, blueHole = false
            
            /// 기울이는 방향에 따라 어느 구슬이 먼저 움직이는지 결정
            let moveRed = { () -> Void in
                while true {
                    let nry = ry + dy[i]
                    let nrx = rx + dx[i]
                    
                    // 벽인 경우 멈춤
                    if board[nry][nrx] == "#" { break }
                    
                    // 구멍인 경우
                    if board[nry][nrx] == "O" {
                        redHole = true
                        ry = -1 // 구슬이 사라졌음을 표시
                        rx = -1
                        break
                    }
                    
                    // 다른 구슬과 같은 위치인 경우 (단, 구멍에 빠진 구슬은 제외) => 구슬이 같은 위치이면 안됨.!
                    if !blueHole && nry == by && nrx == bx {
                        break
                    }
                    
                    // 이동
                    ry = nry; rx = nrx
                }
            }
            
            let moveBlue = { () -> Void in
                while true {
                    let nby = by + dy[i]
                    let nbx = bx + dx[i]
                    
                    // 벽인 경우 멈춤
                    if board[nby][nbx] == "#" {
                        break
                    }
                    
                    // 구멍인 경우
                    if board[nby][nbx] == "O" {
                        blueHole = true
                        by = -1  // 구슬이 사라졌음을 표시
                        bx = -1
                        break
                    }
                    
                    // 다른 구슬과 같은 위치인 경우 (단, 구멍에 빠진 구슬은 제외)
                    if !redHole && nby == ry && nbx == rx {
                        break
                    }
                    
                    // 이동
                    by = nby
                    bx = nbx
                }
            }
            
            if i == 0 { // 위로 기울이기
                if ry < by { moveRed(); moveBlue() }
                else { moveBlue(); moveRed() }
            } else if i == 1 {  // 아래로
                if ry > by { moveRed(); moveBlue() }
                else { moveBlue(); moveRed() }
            } else if i == 2 {  // 왼쪽으로
                if rx < bx { moveRed(); moveBlue() }
                else { moveBlue(); moveRed() }
            } else {    // 오른쪽
                if rx > bx { moveRed(); moveBlue() }
                else { moveBlue(); moveRed() }
            }
            
            /// 구슬이 한 칸씩 이동하면서 벽. 구멍. 다른 구슬과의 충돌 확인
            
            // 파란 구슬이 구멍에 빠지면 실패
            if blueHole { continue }
            
            // 빨간 구슬만 구멍에 빠지면 성공
            if redHole { return curr.count + 1 }
            
            // 두 구슬 모두 이동이 없으면 다음 방향으로
            if ry == curr.redY && rx == curr.redX && by == curr.blueY && bx == curr.blueX {
                continue
            }
            // 새로운 상태 생성
            let nextState = State(redY: ry, redX: rx, blueY: by, blueX: bx, count: curr.count + 1)
            
            // 방문하지 않은 상태라면 큐에 추가
            if !visited.contains(nextState) {
                queue.append(nextState)
                visited.insert(nextState)
            }
        }
    }
    
    return -1  // 10번 이하로 성공할 수 없는 경우
}

let answer = bfs()
print(answer)