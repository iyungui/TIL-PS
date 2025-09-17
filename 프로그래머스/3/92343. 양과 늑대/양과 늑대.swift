import Foundation

func solution(_ info: [Int], _ edges: [[Int]]) -> Int {
    // 트리 구조 생성 (부모 -> 자식들)
    var children = [Int: [Int]]()
    for edge in edges {
        children[edge[0], default: []].append(edge[1])
    }
    
    var maxSheep = 0
    
    func dfs(_ sheep: Int, _ wolf: Int, _ candidates: Set<Int>) {
        // 현재까지 모은 양의 수가 최대값보다 크면 업데이트
        maxSheep = max(maxSheep, sheep)
        
        // 방문 가능한 모든 노드를 탐색
        for next in candidates {
            if info[next] == 0 { // 다음 노드가 양인 경우
                var newCandidates = candidates
                newCandidates.remove(next) // 방문한 노드 제거
                
                // 방문한 노드의 자식들을 후보에 추가
                if let childNodes = children[next] {
                    for child in childNodes {
                        newCandidates.insert(child)
                    }
                }
                
                dfs(sheep + 1, wolf, newCandidates)
                
            } else { // 다음 노드가 늑대인 경우
                // 늑대를 추가해도 양이 더 많을 때만 방문 가능
                if sheep > wolf + 1 {
                    var newCandidates = candidates
                    newCandidates.remove(next) // 방문한 노드 제거
                    
                    // 방문한 노드의 자식들을 후보에 추가
                    if let childNodes = children[next] {
                        for child in childNodes {
                            newCandidates.insert(child)
                        }
                    }
                    
                    dfs(sheep, wolf + 1, newCandidates)
                }
            }
        }
    }
    
    // 루트 노드(0번)의 자식들을 초기 후보로 설정
    var initialCandidates = Set<Int>()
    if let rootChildren = children[0] {
        for child in rootChildren {
            initialCandidates.insert(child)
        }
    }
    
    // 루트 노드에서 시작 (양 1마리, 늑대 0마리)
    dfs(1, 0, initialCandidates)
    
    return maxSheep
}
