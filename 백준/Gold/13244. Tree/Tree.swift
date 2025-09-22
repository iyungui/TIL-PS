import Foundation
// (1) dfs 한번으로 되는가?
// (2) e = v - 1
func main() {
    var t = Int(readLine()!)!

    while t > 0 {
        let n = Int(readLine()!)!
        let m = Int(readLine()!)!
        var adj = Array(repeating: [Int](), count: n)
        var visited = Array(repeating: false, count: n)
        var cnt = 0

        func dfs(_ here: Int) {
            visited[here] = true

            for next in adj[here] {
                if !visited[next] {
                    dfs(next)
                }
            }
        }

        for _ in 0..<m {
            let edge = readLine()!.split(separator: " ").map { Int($0)! }
            let (a, b) = (edge[0] - 1, edge[1] - 1)

            adj[a].append(b)
            adj[b].append(a)
        }
        
        for i in 0..<n {
            if !visited[i] {
                dfs(i)
                cnt += 1
            }
        }

        if cnt == 1 && m == n - 1 { print("tree") }
        else { print("graph") }

        t -= 1
    }
}

main()