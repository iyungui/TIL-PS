
import Foundation

let input = readLine()!.components(separatedBy: " ").map { Int($0)! }
let n = input[0], m = input[1], k = input[4]
var x = input[3], y = input[2]
var board: [[Int]] = []
for _ in 0..<n {
    let line = readLine()!.components(separatedBy: " ").map { Int($0)! }
    board.append(line)
}

let com = readLine()!.components(separatedBy: " ").map { Int($0)! }


// 주사위 평면도
// back, top, front, bottom, west, east
var dice = [0, 0, 0, 0, 0, 0]

func OutRange(_ ny: Int, _ nx: Int) -> Bool {
    return ny < 0 || ny >= n || nx < 0 || nx >= m
}

func move(direction: Int) {
    var ny: Int = y, nx: Int = x
    // x와 y도 적절히 이동
    switch direction {
    case 1: nx += 1
    case 2: nx -= 1
    case 3: ny -= 1
    case 4: ny += 1
    default: break
    }
    // out range move 라면 무시
    if OutRange(ny, nx) { return }
    
    let temp = dice
    
    switch direction {
    case 1:  // 동쪽으로 굴리기
        // swap(west, top), swap(east, bottom)
        dice[1] = temp[4]  // top <- west
        dice[3] = temp[5]  // bottom <- east
        dice[4] = temp[3]  // west <- bottom
        dice[5] = temp[1]  // east <- top
    case 2:  // 서쪽으로 굴리기
        // swap(west, top), swap(east, bottom) -> swap(top, bottom)
        dice[1] = temp[5]  // top <- east
        dice[3] = temp[4]  // bottom <- west
        dice[4] = temp[1]  // west <- top
        dice[5] = temp[3]  // east <- bottom
    case 3:  // 북쪽으로 굴리기
        // 기존 인덱스 0 ~ 3 를 한칸씩 뒤로 이동?
        dice[0] = temp[1]  // back <- top
        dice[1] = temp[2]  // top <- front
        dice[2] = temp[3]  // front <- bottom
        dice[3] = temp[0]  // bottom <- back
    case 4:  // 남쪽으로 굴리기
        // 기존 인덱스 0 ~ 3 를 한칸씩 앞으로 이동?
        dice[0] = temp[3]  // back <- bottom
        dice[1] = temp[0]  // top <- back
        dice[2] = temp[1]  // front <- top
        dice[3] = temp[2]  // bottom <- front
    default:
        break
    }
    
    y = ny; x = nx
}

// 칸이 0인지 0이 아닌지에 따라 액션
func ChangeValue(_ ny: Int, _ nx: Int) {
    if board[ny][nx] == 0 {
        board[ny][nx] = dice[3]   // 주사위를 굴렸을 때, 이동한 칸에 쓰여 있는 수가 0이면, 주사위의 바닥면에 쓰여 있는 수가 칸에 복사
    } else {
        // 0이 아닌 경우에는 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며, 칸에 쓰여 있는 수는 0이 된다.
        dice[3] = board[ny][nx]
        board[ny][nx] = 0
    }
}

for i in 0..<k {
    let prevX = x, prevY = y
    
    // com[i] 실행 (주사위 굴리기)
    move(direction: com[i])
    
    // 주사위가 실제로 이동했을 경우 (범위 밖으로 나가지 않았을 경우)
    if x != prevX || y != prevY {
        
        // 주사위 값 변경? 혹은 칸 변경
        ChangeValue(y, x)
        
        print(dice[1])
    }
}

