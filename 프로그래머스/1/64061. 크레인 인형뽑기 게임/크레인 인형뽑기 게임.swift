import Foundation

func solution(_ board:[[Int]], _ moves:[Int]) -> Int {
    let n = board.count
    var topIndex = [Int](repeating: 0, count: n)  // 각 열의 다음 인형 위치 추적
    var basket = [Int]()  // 바구니 (스택)
    var result = 0  // 터진 인형 개수
    
    for move in moves {
        let col = move - 1
        
        // 해당 열에서 인형 찾기 (top 인덱스부터 시작)
        while topIndex[col] < n && board[topIndex[col]][col] == 0 {
            topIndex[col] += 1
        }
        
        // 인형이 있으면
        if topIndex[col] < n {
            let doll = board[topIndex[col]][col]
            topIndex[col] += 1  // 다음 인형 위치로 이동
            
            // 바구니에 바로 넣기 (같은 인형이면 터뜨림)
            if !basket.isEmpty && basket.last! == doll {
                basket.removeLast()
                result += 2
            } else {
                basket.append(doll)
            }
        }
    }
    
    return result
}