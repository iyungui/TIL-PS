import Foundation

let input = readLine()!.components(separatedBy: " ").map { Int($0)! }
let N = input[0], M = input[1]
let input2 = readLine()!.components(separatedBy: " ").map { Int($0)! }
var r = input2[0], c = input2[1], d = input2[2]

var arr: [[Int]] = []

for _ in 0..<N {
    let line = readLine()!.components(separatedBy: " ").map { Int($0)! }
    arr.append(line)
}

let dy = [-1, 0, 1, 0]
let dx = [0, 1, 0, -1]
var visited = Array(repeating: Array(repeating: 0, count: M), count: N)
var result = 0

while true {
    // 1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다
    if visited[r][c] == 0 {
        visited[r][c] = 1
        result += 1
    }
    
    var cleaned = false
    
    // 3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우
    for _ in 0..<4 {
        // 3-1. 반시계 방향으로 90도 회전
        d = (d + 3) % 4
        
        // 3-2. 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진
        let ny = r + dy[d]
        let nx = c + dx[d]
        
        if ny >= 0 && ny < N && nx >= 0 && nx < M && arr[ny][nx] == 0 && visited[ny][nx] == 0 {
            r = ny
            c = nx
            cleaned = true
            break
        }
    }
    
    // 2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
    if !cleaned {
        // 후진 방향 계산
        let backDir = (d + 2) % 4
        let ny = r + dy[backDir]
        let nx = c + dx[backDir]
        
        // 2-1. 바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진
        if ny >= 0 && ny < N && nx >= 0 && nx < M && arr[ny][nx] == 0 {
            r = ny
            c = nx
        } else {
            // 2-2. 바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다
            break
        }
    }
}

print(result)
