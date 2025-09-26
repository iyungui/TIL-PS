import Foundation
func solution(_ n:Int, _ k:Int, _ cmd:[String]) -> String {
    var prev = Array(repeating: -1, count: n)
    var next = Array(repeating: -1, count: n)

    for i in 0..<n {
        if i > 0 { prev[i] = i - 1 }
        if i < n - 1 { next[i] = i + 1 }
    }

    var current = k
    var stk = [(Int, Int, Int)]()
    
    var isDeleted = Array(repeating: false, count: n)

    for com in cmd {
        if com == "C" {
            let prevNode = prev[current]
            let nextNode = next[current]

            stk.append((current, prevNode, nextNode))
            isDeleted[current] = true

            if prevNode != -1 { next[prevNode] = nextNode }
            if nextNode != -1 { prev[nextNode] = prevNode }

            if nextNode != -1 {
                current = nextNode
            } else {
                current = prevNode
            }
        }
        else if com == "Z" {
            let (deletedNode, prevNode, nextNode) = stk.removeLast()
            isDeleted[deletedNode] = false

            prev[deletedNode] = prevNode
            next[deletedNode] = nextNode

            if prevNode != -1 { next[prevNode] = deletedNode }
            if nextNode != -1 { prev[nextNode] = deletedNode }
        }
        else {
            let parts = com.split(separator: " ")
            let steps = Int(parts[1])!
            if parts[0] == "U" {
                for _ in 0..<steps {
                    current = prev[current]
                }
            }
            else {
                for _ in 0..<steps {
                    current = next[current]
                }
            }
        }
    }
    var ret = ""
    
    for i in 0..<n {
        ret += isDeleted[i] ? "X" : "O"
    }

    return ret
}