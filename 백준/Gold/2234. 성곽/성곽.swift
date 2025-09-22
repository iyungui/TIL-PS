import Foundation

func solve() {
    let dy = [0, -1, 0, 1]
    let dx = [-1, 0, 1, 0]
    let input = readLine()!.split(separator: " ").map { Int($0)! }
    let (m, n) = (input[0], input[1])
    var walls = [[Int]]()
    var visited = Array(repeating: Array(repeating: 0, count: m), count: n)
    var sizes = [Int]()
    for _ in 0..<n {
        let wall = readLine()!.split(separator: " ").map { Int($0)! }
        walls.append(wall)
    }

    var cnt = 0
    var maxSize = 0
    var big = 0

    func dfs(_ y: Int, _ x: Int, number: Int) -> Int {
        if visited[y][x] != 0 { return 0 }
        visited[y][x] = number
        var size: Int = 1

        for i in 0..<4 {
            if walls[y][x] & (1 << i) != 0 { continue }
            let ny = y + dy[i]
            let nx = x + dx[i]
            size += dfs(ny, nx, number: number)
        }

        return size
    }

    for i in 0..<n {
        for j in 0..<m {
            if visited[i][j] == 0 {
                cnt += 1
                let curSize = dfs(i, j, number: cnt)
                sizes.append(curSize)
                maxSize = max(maxSize, curSize)
            }
        }
    }
    
    for i in 0..<n {
        for j in 0..<m {
            if (i + 1 < n) {
                let a = visited[i][j]
                let b = visited[i + 1][j]

                if a != b {
                    big = max(big, sizes[a - 1] + sizes[b - 1])
                }
            }
            if (j + 1 < m) {
                let a = visited[i][j]
                let b = visited[i][j + 1]

                if a != b {
                    big = max(big, sizes[a - 1] + sizes[b - 1])
                }
            }
        }
    }

    print(cnt)
    print(maxSize)
    print(big)
}

solve()