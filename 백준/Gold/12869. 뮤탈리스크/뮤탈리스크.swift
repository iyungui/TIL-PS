import Foundation

func solve() {

    struct Point {
        let x: Int
        let y: Int
        let z: Int
    }

    // input
    let n = Int(readLine()!)!
    var scv: [Int] = [0, 0, 0]
    let line = readLine()!.components(separatedBy: " ").map { Int($0)! }
    for i in 0..<n {
        scv[i] = line[i]
    }

    let combinations = [
        [9, 3, 1],
        [9, 1, 3],
        [3, 1, 9],
        [3, 9, 1],
        [1, 3, 9],
        [1, 9, 3]
    ]

    var visited = Array(repeating: Array(repeating: Array(repeating: 0, count: 64), count: 64), count: 64)
    var q: [Point] = [Point(x: scv[0], y: scv[1], z: scv[2])]
    visited[scv[0]][scv[1]][scv[2]] = 1

    while !q.isEmpty {
        let cur = q.removeFirst()
        let a = cur.x
        let b = cur.y
        let c = cur.z
        if a == 0 && b == 0 && c == 0 {
            break
        }
        for combi in combinations {
            let na = max(0, a - combi[0])
            let nb = max(0, b - combi[1])
            let nc = max(0, c - combi[2])
            if visited[na][nb][nc] != 0 { continue }
            visited[na][nb][nc] = visited[a][b][c] + 1
            q.append(Point(x: na, y: nb, z: nc))
        }
    }

    print(visited[0][0][0] - 1)
}

solve()