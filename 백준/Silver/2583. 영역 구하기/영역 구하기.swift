import Foundation

let input = readLine()!.components(separatedBy: " ").map { Int($0)! }
let n = input[0], m = input[1], k = input[2]
var arr = Array(repeating: Array(repeating: 0, count: m), count: n)
for _ in 0..<k {
    let line = readLine()!.components(separatedBy: " ").map { Int($0)! }
    let x1 = line[0], y1 = line[1], x2 = line[2], y2 = line[3]
    
    // 1. 사각형 칠하기
    for y in y1..<y2 {
        for x in x1..<x2 {
            arr[y][x] = 1
        }
    }
}

var res: [Int] = []
var cnt = 0
var visited = Array(repeating: Array(repeating: 0, count: m), count: n)
let dy = [-1,0,1,0]
let dx = [0,1,0,-1]
for i in 0..<n {
    for j in 0..<m {
        if arr[i][j] == 0 && visited[i][j] == 0 {
            res.append(go(i, j))
            cnt += 1
        }
    }
}

func go(_ y: Int, _ x: Int) -> Int {
    visited[y][x] = 1
    var ret = 1
    for i in 0..<4 {
        let ny = y + dy[i]
        let nx = x + dx[i]
        if ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] == 1 {
            continue
        }
        if arr[ny][nx] == 1 { continue }
        
        ret += go(ny, nx)
    }
    return ret
}

let sortedRes = res.sorted().map { String($0) }.joined(separator: " ")

print(cnt)

print(sortedRes)
