import Foundation
// connected components 문제!

// 전역 변수
let t = Int(readLine()!)!
let dy = [-1, 0, 1, 0]
let dx = [0, 1, 0, -1]

func dfs(_ y: Int, _ x: Int, _ arr: [[Int]], _ visited: inout [[Int]], _ n: Int, _ m: Int) {
    visited[y][x] = 1

    for i in 0..<4 {
        let ny = y + dy[i]
        let nx = x + dx[i]

        if ny < 0 || ny >= n || nx < 0 || nx >= m { continue }
        if visited[ny][nx] == 0 && arr[ny][nx] == 1 { 
            dfs(ny, nx, arr, &visited, n, m)
        }  
    }
}

// arr, n, m, visited 는 테스트 케이스마다 초기화를 시켜야 하는 것에 유의해야 함.

for _ in 0..<t {
    let input = readLine()!.components(separatedBy: " ").map { Int($0)! }
    let (n, m, k) = (input[0], input[1], input[2])

    var arr = Array(repeating: Array(repeating: 0, count: m), count: n)
    var visited = Array(repeating: Array(repeating: 0, count: m), count: n)
    var cnt = 0  // 각 테스트케이스마다 초기화

    for _ in 0..<k {
        let pos = readLine()!.components(separatedBy: " ").map { Int($0)! }
        arr[pos[0]][pos[1]] = 1
    }

    for i in 0..<n {
        for j in 0..<m {
            if visited[i][j] == 0 && arr[i][j] == 1 {
                dfs(i, j, arr, &visited, n, m)
                cnt += 1
            }
        }
    }

    print(cnt)
}