import Foundation

let line = readLine()!.components(separatedBy: " ").map { Int($0)! }
let (n, m, k) = (line[0], line[1], line[2])
var arr: [[Int]] = Array(repeating: Array(repeating: 0, count: m), count: n)

var cnt = 0
var result: [Int] = []
var visited: [[Int]] = Array(repeating: Array(repeating: 0, count: m), count: n)

let dy = [-1, 0, 1, 0]
let dx = [0, 1, 0, -1]

func go(_ y: Int, _ x: Int) -> Int {
    visited[y][x] = 1
    var ret = 1

    for i in 0..<4 {
        let ny = y + dy[i]
        let nx = x + dx[i]

        if ny < 0 || ny >= n || nx < 0 || nx >= m  { continue }
        if visited[ny][nx] == 0 && arr[ny][nx] == 0 {
            ret += go(ny, nx)
        }
    }

    return ret
}

// 직사각형 채우기
for _ in 0..<k {
    let input = readLine()!.components(separatedBy: " ").map { Int($0)! }
    let (x1, y1, x2, y2) = (input[0], input[1], input[2], input[3])
    
    for y in y1..<y2 {
        for x in x1..<x2 {
            arr[y][x] = 1
        }
    }
}

for i in 0..<n {
    for j in 0..<m {
        if visited[i][j] == 0 && arr[i][j] == 0 {
            result.append(go(i, j))
            cnt += 1
        }
    }
}

let sortedResult = result.sorted().map { String($0) }.joined(separator: " ")
print(cnt)
print(sortedResult)