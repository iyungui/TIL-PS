import Foundation

func dijkstra(_ start: Int, _ n: Int, _ graph: [Int: [(Int, Int)]]) -> [Int] {
    var dist = Array(repeating: Int.max / 3, count: n + 1)
    dist[start] = 0

    var pq: [(cost: Int, node: Int)] = [(0, start)]

    while !pq.isEmpty {
        var minIndex = 0
        for i in 1..<pq.count {
            if pq[i].cost < pq[minIndex].cost { minIndex = i }
        }
        let (cost, node) = pq.remove(at: minIndex)

        // 이미 처리된 노드면 스킵
        if dist[node] < cost { continue }

        // 인접 노드 확인
        for (next, nextCost) in graph[node, default: []] {
            let newCost = cost + nextCost
            if newCost < dist[next] {
                dist[next] = newCost
                pq.append((newCost, next))
            }
        }
    }

    return dist
}

func solution(_ n:Int, _ s:Int, _ a:Int, _ b:Int, _ fares:[[Int]]) -> Int {
    // 그래프 만들기 fares -> adj List
    var adj = [Int: [(Int, Int)]]()
    for fare in fares {
        let (c, d, f) = (fare[0], fare[1], fare[2])
        adj[c, default: []].append((d, f))
        adj[d, default: []].append((c, f))
    }

    // 다익스트라 3번 실행 (s, a, b에서 각각)
    let distS: [Int] = dijkstra(s, n, adj)
    let distA: [Int] = dijkstra(a, n, adj)
    let distB: [Int] = dijkstra(b, n, adj)

    var ret = Int.max

    for x in 1..<(n + 1) {
        let cost = distS[x] + distA[x] + distB[x]
        ret = min(ret, cost)
    }

    return ret
}