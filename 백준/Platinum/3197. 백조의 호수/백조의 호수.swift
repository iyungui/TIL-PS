import Foundation

func solve() {
    struct Point {
        let y: Int
        let x: Int
    }

    let dy = [-1, 0, 1, 0]
    let dx = [0, 1, 0, -1]

    let line = readLine()!.components(separatedBy: " ").map { Int($0)! }
    let (r, c) = (line[0], line[1])
    var arr: [[Character]] = []
    for _ in 0..<r {
        let input = Array(readLine()!)
        arr.append(input)
    }

    var swanY: Int = 0, swanX: Int = 0
    var waterQ: [Point] = []
    var waterTempQ: [Point] = []
    var swanQ: [Point] = []
    var swanTempQ: [Point] = []
    var day = 0
    var waterQIndex = 0
    var swanQIndex = 0

    // 백조가 해당 위치를 방문했는지 여부
    var visitedSwan = Array(repeating: Array(repeating: false, count: c), count: r)
    var visited = Array(repeating: Array(repeating: false, count: c), count: r)

    for i in 0..<r {
        for j in 0..<c {
            if arr[i][j] == "L" {
                swanY = i
                swanX = j
            }
            if arr[i][j] == "." || arr[i][j] == "L" {
                visited[i][j] = true
                waterQ.append(Point(y: i, x: j))
            }
        }
    }
    
    swanQ.append(Point(y: swanY, x: swanX))
    visitedSwan[swanY][swanX] = true

    func waterMelting() {
        while waterQIndex < waterQ.count {
            let cur = waterQ[waterQIndex]
            waterQIndex += 1

            for i in 0..<4 {
                let ny = cur.y + dy[i]
                let nx = cur.x + dx[i]

                if ny < 0 || ny >= r || nx < 0 || nx >= c || visited[ny][nx] { continue }
                if arr[ny][nx] == "X" {
                    visited[ny][nx] = true
                    waterTempQ.append(Point(y: ny, x: nx))
                    arr[ny][nx] = "."
                }
            }
        }
    }

    func moveSwan() -> Bool {
        while swanQIndex < swanQ.count {
            let cur = swanQ[swanQIndex]
            swanQIndex += 1

            for i in 0..<4 {
                let ny = cur.y + dy[i]
                let nx = cur.x + dx[i]

                if ny < 0 || ny >= r || nx < 0 || nx >= c || visitedSwan[ny][nx] { continue }
                visitedSwan[ny][nx] = true
                if arr[ny][nx] == "." { 
                    swanQ.append(Point(y: ny, x: nx)) 
                }
                else if arr[ny][nx] == "X" { 
                    swanTempQ.append(Point(y: ny, x: nx)) 
                }
                else if arr[ny][nx] == "L" { 
                    return true 
                }
            }
        }
        return false
    }

    while true {
        // 만약 두 백조가 만날 수 있다면
        if moveSwan() { break }
        waterMelting()
        
        // 큐 교체 및 인덱스 초기화
        waterQ = waterTempQ
        swanQ = swanTempQ
        waterTempQ = []
        swanTempQ = []
        waterQIndex = 0  // 중요: 인덱스 초기화
        swanQIndex = 0   // 중요: 인덱스 초기화

        day += 1
    }

    print(day)
}

solve()