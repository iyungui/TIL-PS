import Foundation

func solution(_ edges:[[Int]]) -> [Int] {
    var inDegree = [Int: Int]()
    var outDegree = [Int: Int]()
    for edge in edges {
        let from = edge[0]
        let to = edge[1]
        inDegree[to, default: 0] += 1
        outDegree[from, default: 0] += 1
    }
    var createdVertex = -1
    for vertex in outDegree.keys {
        if inDegree[vertex, default: 0] == 0 && outDegree[vertex]! >= 2 {
            createdVertex = vertex; break
        }
    }
    var total = outDegree[createdVertex]!
    var stick = 0, eight = 0
    
    for vertex in inDegree.keys {
        let inDeg = inDegree[vertex, default: 0]
        let outDeg = outDegree[vertex, default: 0]
        if outDeg == 0 { stick += 1 }
        else if inDeg >= 2 && outDeg == 2 { eight += 1 }
    }
    
    return [createdVertex, total - stick - eight, stick, eight]
}