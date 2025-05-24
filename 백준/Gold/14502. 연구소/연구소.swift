import Foundation

let input = readLine()!.components(separatedBy: " ").map { Int($0)! }
let n = input[0], m = input[1]

var arr = [[Int]]()
var virusList = [(Int, Int)]()
var wallList = [(Int, Int)]()
var ret = 0
var visited: [[Int]] = []
let dy = [-1, 0, 1, 0]
let dx = [0, 1, 0, -1]

for _ in 0..<n {
    let line = readLine()!.components(separatedBy: " ").map { Int($0)! }
    arr.append(line)
}

for i in 0..<n {
    for j in 0..<m {
        if arr[i][j] == 2 { virusList.append((i, j)) }
        else if arr[i][j] == 0 { wallList.append((i, j)) }
    }
}

for i in 0..<wallList.count {
    for j in 0..<i {
        for k in 0..<j {
            arr[wallList[i].0][wallList[i].1] = 1
            arr[wallList[j].0][wallList[j].1] = 1
            arr[wallList[k].0][wallList[k].1] = 1
            ret = max(solve(), ret)
            arr[wallList[i].0][wallList[i].1] = 0
            arr[wallList[j].0][wallList[j].1] = 0
            arr[wallList[k].0][wallList[k].1] = 0
        }
    }
}

print(ret)

func solve() -> Int {
    visited = Array(repeating: Array(repeating: 0, count: m), count: n)
    
    for virus in virusList {
        visited[virus.0][virus.1] = 1
        go(virus.0, virus.1)
    }
    
    var cnt = 0
    for i in 0..<n {
        for j in 0..<m {
            if arr[i][j] == 0 && visited[i][j] == 0 {
                cnt += 1
            }
        }
    }
    return cnt
}

func go(_ y: Int, _ x: Int) {
    for i in 0..<4 {
        let ny = y + dy[i]
        let nx = x + dx[i]
        
        if ny < 0 || ny >= n || nx < 0 || nx >= m { continue }
        
        if (arr[ny][nx] == 0 || arr[ny][nx] == 2) && visited[ny][nx] == 0 {
            visited[ny][nx] = 1
            go(ny, nx)
        }
    }
}