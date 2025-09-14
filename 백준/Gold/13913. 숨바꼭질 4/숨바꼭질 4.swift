import Foundation

func solution() {
    let MAX_N = 200004
    let line = readLine()!.components(separatedBy: " ").map { Int($0)! }
    let (n, k) = (line[0], line[1])

    if n == k {
        print(0)
        print(n)
        return
    }

    var visited = Array(repeating: false, count: MAX_N)
    var distance = Array(repeating: 0, count: MAX_N)
    var prev: [Int] = Array(repeating: -1, count: MAX_N)

    var q: [Int] = []
    var queueIndex = 0
    q.append(n)
    visited[n] = true

    while queueIndex < q.count {
        let here = q[queueIndex]
        queueIndex += 1

        if here == k {
            break
        }
        
        for next in [here + 1, here - 1, 2 * here] {
            if next >= 0 && next < MAX_N && !visited[next] {
                visited[next] = true
                distance[next] = distance[here] + 1
                prev[next] = here
                q.append(next)
            }
        }
    }

    var path: [Int] = [k]
    var current = prev[k]
    while current != -1 {
        path.append(current)
        current = prev[current]
    }

    path.reverse()

    print(distance[k])
    for p in path {
        print(p, terminator: " ")
    }
}

solution()