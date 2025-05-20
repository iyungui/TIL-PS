import Foundation

var t = Int(readLine()!)!
let dy = [-1 ,0, 1, 0]
let dx = [0, 1, 0, -1]
var visited: [[Int]] = []
var arr: [[Int]] = []
var N: Int = 0, M: Int = 0, K: Int = 0

func dfs(_ y: Int, _ x: Int) {
    for i in 0..<4 {
        let ny = y + dy[i]
        let nx = x + dx[i]
        
        if ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx] == 1 || arr[ny][nx] == 0 { continue }
        
        visited[ny][nx] = 1
        dfs(ny, nx)
    }
}

while t > 0 {
    let line = readLine()!.components(separatedBy: " ").map { Int($0)! }
    M = line[0]; N = line[1]; K = line[2]
    var cnt = 0
    arr = Array(repeating: Array(repeating: 0, count: M), count: N)
    visited = Array(repeating: Array(repeating: 0, count: M), count: N)
    
    for _ in 0..<K {
        let line = readLine()!.components(separatedBy: " ").map { Int($0)! }
        arr[line[1]][line[0]] = 1
    }
    
    for i in 0..<N {
        for j in 0..<M {
            if arr[i][j] == 1 && visited[i][j] == 0 {
                dfs(i, j)
                cnt += 1
            }
        }
    }
    
    t -= 1
    print(cnt)
}