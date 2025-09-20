import Foundation

func solution(_ n:Int, _ m:Int, _ x:Int, _ y:Int, _ r:Int, _ c:Int, _ k:Int) -> String {
    let minDist = abs(x - r) + abs(y - c)
    if k < minDist || (k - minDist) % 2 != 0 { return "impossible" }
    
    var visited = Array(repeating: Array(repeating: Array(repeating: false, count: k + 1), count: m + 1), count: n + 1)
    
    let dy = [1, 0, 0, -1]
    let dx = [0, -1, 1, 0]
    let direction = ["d", "l", "r", "u"]
    
    func go(_ y: Int, _ x: Int, _ remain: Int, _ path: String) -> String? {
        if y == r && x == c && remain == 0 {
            return path
        }
        if remain == 0 { return nil }
        
        let minDist = abs(y - r) + abs(x - c)
        
        if remain < minDist || (remain - minDist) % 2 != 0 { return nil }
        
        for i in 0..<4 {
            let ny = y + dy[i]
            let nx = x + dx[i]
            
            if ny < 1 || ny > n || nx < 1 || nx > m { continue }
            if visited[ny][nx][remain] { continue }
            visited[ny][nx][remain] = true
            if let result = go(ny, nx, remain - 1, path + direction[i]) {
                return result
            }
        }
        return nil
    }
    
    visited[x][y][k] = true
    if let result = go(x, y, k, "") { return result }
    else { return "impossible" }
}