let input = readLine()!.split(separator: " ").map { Int($0)! }
let (r, c, k) = (input[0], input[1], input[2])
var arr: [[Character]] = []
for _ in 0..<r {
    let line = Array(readLine()!)
    arr.append(line)
} 

var visited = Array(repeating: Array(repeating: 0, count: c), count: r)

let dy = [-1, 0, 1, 0]
let dx = [0, 1, 0, -1]

func go(_ y: Int, _ x: Int) -> Int {
    if y == 0 && x == c - 1 {
        if visited[y][x] == k {
            return 1
        } else {
            return 0
        }
    }

    if visited[y][x] >= k { return 0 }
    var ret = 0
    for i in 0..<4 {
        let ny = y + dy[i], nx = x + dx[i]

        if ny < 0 || ny >= r || nx < 0 || nx >= c { continue }
        if visited[ny][nx] != 0 || arr[ny][nx] == "T" { continue }
        visited[ny][nx] = visited[y][x] + 1
        ret += go(ny, nx)
        visited[ny][nx] = 0
    }

    return ret
}

visited[r - 1][0] = 1
let res = go(r - 1, 0)

print(res)
