import Foundation

let line = readLine()!.components(separatedBy: " ").map { Int($0)! }
let n = line[0], m = line[1]
var a: [[Int]] = []
for _ in 0..<n {
    let s = readLine()!.map { Int(String($0))! }
    a.append(s)
}

let dy = [-1, 0, 1, 0]
let dx = [0, 1, 0, -1]
var visited = Array(repeating: Array(repeating: 0, count: m), count: n)

// (y, x)
var queue = [(Int, Int)]()

// 시작점 (0, 0)
queue.append((0, 0))
visited[0][0] = 1

var front = 0

while front < queue.count {
    let (y, x) = queue[front]
    front += 1

    // 도착점에 도달하면 break
    if y == n - 1 && x == m - 1 {
        break
    }

    for i in 0..<4 {
        let ny = y + dy[i]
        let nx = x + dx[i]

        if ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 0 { continue }
        if visited[ny][nx] != 0 { continue }

        visited[ny][nx] = visited[y][x] + 1
        queue.append((ny, nx))
    }
}

print(visited[n - 1][m - 1])