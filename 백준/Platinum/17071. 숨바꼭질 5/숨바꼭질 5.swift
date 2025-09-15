import Foundation

func main() -> Int {
    let input = readLine()!.split(separator: " ").map { Int($0)! }
    let a = input[0]    // 수빈 위치
    var b = input[1]    // 동생 위치
    
    // early return: 수빈이와 동생의 위치가 같을 때
    if a == b {
        return 0
    }

    let maxN = 500000
    // visited[홀수/짝수][위치] - 해당 턴(홀수/짝수)에 해당 위치 방문 가능 여부
    var visited = Array(repeating: Array(repeating: false, count: maxN + 4), count: 2)
    
    var queue = [a]
    visited[0][a] = true  // 0초(짝수)에 수빈이 시작 위치 방문
    
    var queueIndex = 0
    var turn = 1
    var ok = false
    
    while queueIndex < queue.count {
        // 동생 위치 업데이트 (매 초마다 turn만큼 이동)
        b += turn
        
        // 동생이 범위를 벗어나면 종료
        if b > maxN {
            break
        }
        
        // 현재 턴에 동생 위치에 수빈이가 도달할 수 있는지 체크
        if visited[turn % 2][b] {
            ok = true
            break
        }
        
        let currentQueueSize = queue.count
        
        // 현재 큐에 있는 모든 위치에서 다음 이동 처리
        while queueIndex < currentQueueSize {
            let currentPos = queue[queueIndex]
            queueIndex += 1
            
            // 세 가지 이동 방법: -1, +1, *2
            let nextPositions = [currentPos - 1, currentPos + 1, currentPos * 2]
            
            for nextPos in nextPositions {
                // 범위 체크
                if nextPos < 0 || nextPos > maxN {
                    continue
                }
                
                // 이미 현재 턴에 방문했는지 체크
                if visited[turn % 2][nextPos] {
                    continue
                }
                
                // 방문 처리
                visited[turn % 2][nextPos] = true
                
                // 동생과 만났는지 체크
                if nextPos == b {
                    ok = true
                    break
                }
                
                // 다음 탐색을 위해 큐에 추가
                queue.append(nextPos)
            }
            
            if ok {
                break
            }
        }
        
        if ok {
            break
        }
        
        turn += 1
    }
    
    return ok ? turn : -1
}

print(main())