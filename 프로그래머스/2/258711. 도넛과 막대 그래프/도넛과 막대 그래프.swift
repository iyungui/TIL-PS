import Foundation

func solution(_ edges:[[Int]]) -> [Int] {
    var inDegree = [Int: Int]()
    var outDegree = [Int: Int]()
    
    for edge in edges {
        let a = edge[0], b = edge[1]
        // graph 인접리스트를 만들지 않고,
        // (중요) in/outDegree에 key에는 vertex 번호를, value에는 해당 vertex에서 간선의 개수를 저장
        inDegree[b, default: 0] += 1
        outDegree[a, default: 0] += 1
    }
    
    var createdVertex = -1
    
    for vertex in outDegree.keys {
        // 도넛, 막대, 8자 모양 그래프의 수의 합은 2 이상이어야 한다.
        // 그러므로 inDegree가 0인 정점 중에서, outDegree 의 갯수도 최소 2 이상인 곳이, 생성 정점이다
        if inDegree[vertex] ?? 0 == 0 && outDegree[vertex]! >= 2 {
            createdVertex = vertex; break
        }
    }
    
    // 전체 그래프의 수 = createdVertex에서 뻗어나간 간선의 개수
    let totalGraphCount = outDegree[createdVertex] ?? 0
    var stick = 0
    var eight = 0
    
    // 생성 정점에서 뻗어나간 그래프의 처음은 모두 inDegree에서 시작
    for vertex in inDegree.keys {
        let outDeg = outDegree[vertex, default: 0]
        let inDeg = inDegree[vertex, default: 0]
        
        // 막대 모양 그래프가 하나 있다는 것은, outDegree가 0인 정점(막대 그래프의 마지막 정점)이 하나 있다는 것.
        if outDeg == 0 { stick += 1 }
        
        // 8자 모양 그래프가 하나 있다는 것은, inDegree 가 2+, outDegree가 2인 정점이 하나 있다는 것.
        if inDeg >= 2 && outDeg == 2 { eight += 1 }
    }
    
    // 도넛 모양 그래프 개수는 전체 그래프 개수 - 막대 - 8자 그래프를 빼면 구할 수 있다
    let donut = totalGraphCount - stick - eight
    return [createdVertex, donut, stick, eight]
}