import Foundation

func solution(_ places:[[String]]) -> [Int] {
    var ret = [Int]()
    for place in places {
        ret.append(allOk(place.map { Array($0) }) ? 1 : 0)
    }
    return ret
}

private func allOk(_ place: [[Character]]) -> Bool {
    func bfs(_ y: Int, _ x:Int) -> Bool {
        let dy = [-1, 0, 1, 0]
        let dx = [0, 1, 0, -1]
        var visited = Array(repeating: Array(repeating: 0, count: 5), count: 5)
        var queue = [(Int, Int)]()
        queue.append((y, x))
        visited[y][x] = 1
        var queueIndex = 0
        
        while queueIndex < queue.count {
            let (y, x) = queue[queueIndex]
            queueIndex += 1

            // if visited[y][x] >= 4 { return false }

            for i in 0..<4 {
                let ny = y + dy[i]
                let nx = x + dx[i]
                
                if ny < 0 || ny >= 5 || nx < 0 || nx >= 5 { continue }
                if visited[ny][nx] != 0 || place[ny][nx] == "X" { continue }
                
                visited[ny][nx] = visited[y][x] + 1

                if place[ny][nx] == "P" && visited[ny][nx] <= 3 { return true }

                queue.append((ny, nx))
            }
        }
        return false
    }
    
    for i in 0..<5 {
        for j in 0..<5 {
            if place[i][j] == "P" {
                if bfs(i, j) { return false }
            }
        }
    }
    return true
}