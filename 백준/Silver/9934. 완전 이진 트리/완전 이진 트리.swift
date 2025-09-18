import Foundation

func solve() {
    let k = Int(readLine()!)!
    let arr = readLine()!.components(separatedBy: " ").map { Int($0)! }
    var ret: [[Int]] = Array(repeating: [], count: k)

    func go(_ left: Int, _ right: Int, _ level: Int) {
        if left > right { return }
        
        let mid = (left + right) / 2
        ret[level].append(arr[mid])
        
        go(left, mid - 1, level + 1)
        go(mid + 1, right, level + 1)
    }

    go(0, arr.count - 1, 0)

    for level in 0..<k {
        for i in 0..<ret[level].count {
            if i > 0 { print(" ", terminator: "") }
            print(ret[level][i], terminator: "")
        }
        print()
    }
}

solve()