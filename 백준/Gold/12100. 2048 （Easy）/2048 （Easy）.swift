import Foundation

// 입력 받기
let n = Int(readLine()!)!
var board: [[Int]] = []

for _ in 0..<n {
    let row = readLine()!.split(separator: " ").map { Int($0)! }
    board.append(row)
}

// 결과 출력
print(solution(board: board))

// 왼쪽으로 이동
func moveLeft(_ board: inout [[Int]]) {
    let n = board.count
    
    for i in 0..<n {
        var row = board[i]
        // 왼쪽으로 밀기 (0 제거)
        row = row.filter { $0 != 0 }
        
        // 같은 값 합치기
        var j = 0
        while j < row.count - 1 {
            if row[j] == row[j + 1] {
                row[j] *= 2
                row.remove(at: j + 1)
            }
            j += 1
        }
        
        // 나머지 부분 0으로 채우기
        while row.count < n {
            row.append(0)
        }
        
        board[i] = row
    }
}

// 오른쪽으로 이동
func moveRight(_ board: inout [[Int]]) {
    let n = board.count
    
    for i in 0..<n {
        var row = board[i]
        // 오른쪽으로 밀기 (0 제거)
        row = row.filter { $0 != 0 }
        
        // 같은 값 합치기 (뒤에서부터)
        var j = row.count - 1
        while j > 0 {
            if row[j] == row[j - 1] {
                row[j] *= 2
                row.remove(at: j - 1)
                j -= 1
            }
            j -= 1
        }
        
        // 앞부분 0으로 채우기
        while row.count < n {
            row.insert(0, at: 0)
        }
        
        board[i] = row
    }
}

// 위로 이동
func moveUp(_ board: inout [[Int]]) {
    let n = board.count
    
    for j in 0..<n {
        var column = [Int]()
        
        // 열 추출
        for i in 0..<n {
            column.append(board[i][j])
        }
        
        // 위로 밀기 (0 제거)
        column = column.filter { $0 != 0 }
        
        // 같은 값 합치기
        var i = 0
        while i < column.count - 1 {
            if column[i] == column[i + 1] {
                column[i] *= 2
                column.remove(at: i + 1)
            }
            i += 1
        }
        
        // 나머지 부분 0으로 채우기
        while column.count < n {
            column.append(0)
        }
        
        // 열 업데이트
        for i in 0..<n {
            board[i][j] = column[i]
        }
    }
}

// 아래로 이동
func moveDown(_ board: inout [[Int]]) {
    let n = board.count
    
    for j in 0..<n {
        var column = [Int]()
        
        // 열 추출
        for i in 0..<n {
            column.append(board[i][j])
        }
        
        // 아래로 밀기 (0 제거)
        column = column.filter { $0 != 0 }
        
        // 같은 값 합치기 (뒤에서부터)
        var i = column.count - 1
        while i > 0 {
            if column[i] == column[i - 1] {
                column[i] *= 2
                column.remove(at: i - 1)
                i -= 1
            }
            i -= 1
        }
        
        // 앞부분 0으로 채우기
        while column.count < n {
            column.insert(0, at: 0)
        }
        
        // 열 업데이트
        for i in 0..<n {
            board[i][j] = column[i]
        }
    }
}

// 방향에 따라 이동 함수 호출
func move(_ board: inout [[Int]], direction: Int) {
    switch direction {
    case 0: // 왼쪽
        moveLeft(&board)
    case 1: // 오른쪽
        moveRight(&board)
    case 2: // 위
        moveUp(&board)
    case 3: // 아래
        moveDown(&board)
    default:
        break
    }
}

// 보드가 변했는지 확인하는 함수
func boardChanged(_ oldBoard: [[Int]], _ newBoard: [[Int]]) -> Bool {
    let n = oldBoard.count
    for i in 0..<n {
        for j in 0..<n {
            if oldBoard[i][j] != newBoard[i][j] {
                return true
            }
        }
    }
    return false
}

// 재귀적으로 최대 블록 값 찾기
func findMaxBlock(currentMoves: Int, currentBoard: [[Int]]) -> Int {
    // 현재 보드에서 최대 블록 값 찾기
    let currentMax = currentBoard.flatMap { $0 }.max() ?? 0
    
    // 기저 조건: 5번 이동 완료
    if currentMoves == 5 {
        return currentMax
    }
    
    var maxBlock = currentMax
    
    // 4방향으로 이동해보기
    for direction in 0..<4 {
        // 보드 복사
        var newBoard = currentBoard
        
        // direction에 따라 이동
        move(&newBoard, direction: direction)
        
        // 이동 후 보드가 변했는지 확인
        if boardChanged(currentBoard, newBoard) {
            // 재귀 호출
            let result = findMaxBlock(currentMoves: currentMoves + 1, currentBoard: newBoard)
            maxBlock = max(maxBlock, result)
        }
    }
    
    return maxBlock
}

// 솔루션 함수
func solution(board: [[Int]]) -> Int {
    return findMaxBlock(currentMoves: 0, currentBoard: board)
}