import Foundation

let n = Int(readLine()!)!

var arr: [[Int]] = []
var visited: [[Int]] = []

let dy = [-1, 0, 1, 0]
let dx = [0, 1, 0, -1]
var t = 0 // 해당 지역의 최대 높이
var res = 1 // 안전영역의 최대 개수

for _ in 0..<n {
    let line = readLine()!.components(separatedBy: " ").map { Int($0)! }
    let maxHeight = line.max()
    if let mh = maxHeight {
        t = max(t, mh)
    }
    arr.append(line)
}

while t > 0 {
    visited = Array(repeating: Array(repeating: 0, count: n), count: n)
    var cnt = 0
    for i in 0..<n {
        for j in 0..<n {
            if arr[i][j] > t && visited[i][j] == 0 {
                dfs(i, j, t)
                cnt += 1
            }
        }
    }
    res = max(res, cnt)
    t -= 1
}

func dfs(_ y: Int, _ x: Int, _ h: Int) {
    for i in 0..<4 {
        let ny = y + dy[i]
        let nx = x + dx[i]
        if ny < 0 || ny >= n || nx < 0 || nx >= n || arr[ny][nx] <= h || visited[ny][nx] == 1 { continue }
        visited[ny][nx] = 1
        dfs(ny, nx, h)
    }
}

print(res)
