import Foundation

func main() {
    let input = readLine()!.split(separator: " ").map { Int($0)! }
    let (n, l) = (input[0],input[1])
    var a = [[Int]]()
    var b = Array(repeating: Array(repeating: 0, count: n), count: n)
    for _ in 0..<n {
        let line = readLine()!.split(separator: " ").map { Int($0)! }
        a.append(line)
    }

    for i in 0..<n {
        for j in 0..<n {
            b[j][i] = a[i][j]
        }
    }

    var ret = 0

    func solve(_ arr: [[Int]]) {
        for i in 0..<n {
            var cnt = 1
            var j = 0

            while j < n - 1 {
                if arr[i][j] == arr[i][j + 1] { cnt += 1 }
                // 오르막길
                else if arr[i][j] + 1 == arr[i][j + 1] && cnt >= l { cnt = 1 }
                // 내리막길
                else if arr[i][j] - 1 == arr[i][j + 1] && cnt >= 0 { cnt = -l + 1 }
                else { break }
                j += 1
            }
            
            if j == n - 1 && cnt >= 0 { ret += 1 }
        }
    }

    solve(a); solve(b)
    print(ret)
}

main()