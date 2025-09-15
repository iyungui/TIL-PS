import Foundation

func solve() {
    let dy = [-1, 0, 1, 0]
    let dx = [0, 1, 0, -1]

    let input = readLine()!.split(separator: " ").map { Int($0)! }
    let (n, m) = (input[0], input[1])

    let input2 = readLine()!.split(separator: " ").map { Int($0)! }
    let (y1,x1,y2,x2) = (input2[0] - 1, input2[1] - 1, input2[2] - 1, input2[3] - 1)
    var arr: [[Character]] = []
    for _ in 0..<n {
        let line = Array(readLine()!)
        arr.append(line)
    }
    var visited = Array(repeating: Array(repeating: 0, count: m), count: n)
    visited[y1][x1] = 1
    var queue: [Int] = [1000 * y1 + x1]
    var queueIndex = 0
    var jump = 0

    while arr[y2][x2] != "0" {
        jump += 1
        
        var temp: [Int] = []

        while queueIndex < queue.count {
            let cur = queue[queueIndex]
            let y = cur / 1000
            let x = cur % 1000
            queueIndex += 1

            for i in 0..<4 {
                let ny = y + dy[i]
                let nx = x + dx[i]

                if ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] != 0 { continue }
                visited[ny][nx] = jump

                if arr[ny][nx] != "0" {
                    arr[ny][nx] = "0"
                    temp.append(1000 * ny + nx)
                } else {
                    queue.append(1000 * ny + nx)
                }
            }
        }

        queue = temp
        queueIndex = 0
    }

    print(visited[y2][x2])
}   

solve()