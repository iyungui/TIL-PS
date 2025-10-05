import Foundation

func solution(_ board:[[Int]], _ moves:[Int]) -> Int {
    let n = board.count, m = board[0].count
    var a = Array(repeating: Array(repeating: 0, count: n), count: m)

    for i in 0..<n {
        for j in 0..<m {
            a[j][i] = board[i][j]
        }
    }
    
    var arr = [Int]()
    
    for move in moves {
        for (offset, element) in a[move - 1].enumerated() {
            if element != 0 {
                arr.append(element)
                a[move - 1][offset] = 0
                break
            }
        }
    }
    
    var stk = [Int]()
    
    for i in 0..<arr.count {
        if !stk.isEmpty && stk.last! == arr[i] {
            stk.removeLast()
        }
        else {
            stk.append(arr[i])
        }
    }
    
    return arr.count - stk.count
}