import Foundation

func solution(_ priorities:[Int], _ location:Int) -> Int {
    // 튜플 사용 (우선순위, 원래 위치)
    var queue: [(priority: Int, originalIndex: Int)] = priorities.enumerated().map { ($1, $0) }
    var count = 0   // 큐에서 꺼낸 횟수
    
    while !queue.isEmpty {
        let current = queue.removeFirst()
        
        // 남은 프로세스 중에서 더 높은 우선순위를 가진 프로세스가 있는지 확인
        if queue.contains(where: { $0.priority > current.priority }) {
            // 있다면 현재 프로세스를 큐의 맨 뒤로 이동
            queue.append(current)
        } else {
            // 없다면 현재 프로세스를 실행
            count += 1
            
            // current가 우리가 찾는 프로세스인지 확인
            if current.originalIndex == location { return count }
        }
    }
    return 0
}