import Foundation

func solution() {
    let line = readLine()!.components(separatedBy: " ").map { Int($0)! }
    let (n, m) = (line[0], line[1])
    let MAX = 200000
    if n == m { print(0, 1); return }

    var visited = Array(repeating: 0, count: MAX + 4)
    var cnt = Array(repeating: 0, count: MAX + 4)

    visited[n] = 1
    cnt[n] = 1
    var q: [Int] = []
    var queueIndex = 0
    q.append(n)

    while queueIndex < q.count {
        let now = q[queueIndex]
        queueIndex += 1

        for next in [now - 1, now + 1, 2 * now] {
            if next >= 0 && next <= MAX {
                if visited[next] == 0 {
                    q.append(next)
                    visited[next] = visited[now] + 1
                    cnt[next] += cnt[now]
                } else if visited[next] == visited[now] + 1 {
                    cnt[next] += cnt[now]
                }
            }
        }
    }

    print(visited[m] - 1, cnt[m])
    return
}

solution()

