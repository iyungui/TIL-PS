
import Foundation

// 좌표 구조체
struct Point: Equatable {
    let x: Int
    let y: Int
}

// 방향 열거형
enum Direction {
    case up, right, down, left
    
    func turnRight() -> Direction {
        switch self {
        case .up: return .right
        case .right: return .down
        case .down: return .left
        case .left: return .up
        }
    }
    
    func turnLeft() -> Direction {
        switch self {
        case .up: return .left
        case .right: return .up
        case .down: return .right
        case .left: return .down
        }
    }
    
    func nextPoint(from point: Point) -> Point {
        switch self {
        case .up: return Point(x: point.x - 1, y: point.y)
        case .right: return Point(x: point.x, y: point.y + 1)
        case .down: return Point(x: point.x + 1, y: point.y)
        case .left: return Point(x: point.x, y: point.y - 1)
        }
    }
}

// 방향 전환 정보 구조체
struct Turn {
    let time: Int
    let direction: Character // 'L' 또는 'D'
}

// 시뮬레이션 함수
func simulate(boardSize: Int, apples: [Point], turns: [Turn]) -> Int {
    var board = Array(repeating: Array(repeating: false, count: boardSize + 1), count: boardSize + 1)
    
    // 사과 위치 표시
    for apple in apples {
        board[apple.x][apple.y] = true
    }
    
    var snake = [Point(x: 1, y: 1)] // 뱀의 위치 (머리가 마지막 요소)
    var direction = Direction.right // 초기 방향
    var time = 0
    var turnIndex = 0
    
    while true {
        time += 1
        
        // 1. 머리를 다음 칸에 위치
        let head = snake.last!
        let nextHead = direction.nextPoint(from: head)
        
        // 2. 벽에 부딪히는지 검사
        if nextHead.x < 1 || nextHead.x > boardSize || nextHead.y < 1 || nextHead.y > boardSize {
            break
        }
        
        // 3. 자기 자신의 몸에 부딪히는지 검사
        if snake.contains(nextHead) {
            break
        }
        
        // 4. 머리 이동
        snake.append(nextHead)
        
        // 5. 사과가 있는지 확인
        if board[nextHead.x][nextHead.y] {
            // 사과가 있으면 꼬리는 그대로
            board[nextHead.x][nextHead.y] = false // 사과 제거
        } else {
            // 사과가 없으면 꼬리 이동 (제거)
            snake.removeFirst()
        }
        
        // 6. 방향 전환 처리
        if turnIndex < turns.count && time == turns[turnIndex].time {
            if turns[turnIndex].direction == "L" {
                direction = direction.turnLeft()
            } else {
                direction = direction.turnRight()
            }
            turnIndex += 1
        }
    }
    
    return time
}

// 입력 처리
func solution() -> Int {
    let n = Int(readLine()!)!
    let k = Int(readLine()!)!
    
    var apples: [Point] = []
    for _ in 0..<k {
        let input = readLine()!.split(separator: " ").map { Int($0)! }
        apples.append(Point(x: input[0], y: input[1]))
    }
    
    let l = Int(readLine()!)!
    var turns: [Turn] = []
    for _ in 0..<l {
        let input = readLine()!.split(separator: " ")
        let time = Int(input[0])!
        let direction = Character(String(input[1]))
        turns.append(Turn(time: time, direction: direction))
    }
    
    return simulate(boardSize: n, apples: apples, turns: turns)
}

print(solution())
