import Foundation

let input = readLine()!.components(separatedBy: " ").map { Int($0)! }
let N = input[0], M = input[1]

var wallList: [(Int, Int)] = []  // 빈 칸 (벽을 세울 수 있는 곳들) (y, x)
var virusList: [(Int, Int)] = []    // 처음 바이러스가 있던 곳들   (y, x)
var arr: [[Int]] = []
var result = 0
var visited: [[Int]] = Array(repeating: Array(repeating: 0, count: M), count: N)
var dy: [Int] = [-1, 0, 1, 0]
var dx: [Int] = [0, 1, 0, -1]

for _ in 0..<N {
    let line = readLine()!.components(separatedBy: " ").map { Int($0)! }
    arr.append(line)
}

for i in 0..<N {
    for j in 0..<M {
        if arr[i][j] == 0 { wallList.append((i, j)) }
        else if arr[i][j] == 2 { virusList.append((i, j)) }
    }
}

func dfs(_ y: Int, _ x: Int) -> Void {
    for i in 0..<4 {
        let ny = y + dy[i]
        let nx = x + dx[i]
        
        if ny < 0 || ny >= N || nx < 0 || nx >= M { continue }
        if visited[ny][nx] == 1 { continue }
        if arr[ny][nx] == 1 { continue }
        
        visited[ny][nx] = 1
        dfs(ny, nx)
    }
    return
}

func countSafeArea() -> Int {
    visited = Array(repeating: Array(repeating: 0, count: M), count: N)
    
    // 바이러스 퍼트리기
    for virus in virusList {
        visited[virus.0][virus.1] = 1
        dfs(virus.0, virus.1)
    }
    
    // 안전영역의 개수를 구하기
    var cnt = 0
    for i in 0..<N {
        for j in 0..<M {
            if visited[i][j] == 1 || arr[i][j] == 2 { continue }
            if arr[i][j] == 1 { continue }
            cnt += 1
        }
    }
    
    return cnt
}

for i in 0..<wallList.count {
    for j in 0..<i {
        for k in 0..<j {
            arr[wallList[i].0][wallList[i].1] = 1
            arr[wallList[j].0][wallList[j].1] = 1
            arr[wallList[k].0][wallList[k].1] = 1
            result = max(result, countSafeArea())
            arr[wallList[i].0][wallList[i].1] = 0
            arr[wallList[j].0][wallList[j].1] = 0
            arr[wallList[k].0][wallList[k].1] = 0
        }
    }
}

print(result)