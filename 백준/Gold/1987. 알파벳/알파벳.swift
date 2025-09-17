import Foundation

func solve() {
    let line = readLine()!.split(separator: " ").map { Int($0)! }
    let (r, c) = (line[0], line[1])
    var board: [[Int]] = []
    
    // 문자를 숫자로 미리 변환하여 저장
    for _ in 0..<r {
        let input = readLine()!
        let row = input.map { Int($0.asciiValue!) - Int(Character("A").asciiValue!) }
        board.append(row)
    }
    
    // 비트마스킹을 사용한 visited 관리 (더 빠름)
    var visited = 0
    var maxCount = 0
    
    let dy = [-1, 0, 1, 0]
    let dx = [0, 1, 0, -1]
    
    func dfs(_ y: Int, _ x: Int, _ count: Int, _ visitedMask: Int) {
        maxCount = max(maxCount, count)
        
        for i in 0..<4 {
            let ny = y + dy[i]
            let nx = x + dx[i]
            
            // 경계 체크
            if ny < 0 || ny >= r || nx < 0 || nx >= c { continue }
            
            let nextChar = board[ny][nx]
            let nextBit = 1 << nextChar
            
            // 이미 방문한 알파벳인지 체크
            if (visitedMask & nextBit) != 0 { continue }
            
            // 재귀 호출 (비트마스킹으로 방문 처리)
            dfs(ny, nx, count + 1, visitedMask | nextBit)
        }
    }
    
    // 시작 위치의 알파벳으로 비트마스크 초기화
    let startBit = 1 << board[0][0]
    dfs(0, 0, 1, startBit)
    
    print(maxCount)
}

solve()