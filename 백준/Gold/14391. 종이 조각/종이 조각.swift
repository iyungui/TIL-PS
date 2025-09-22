import Foundation

func solve() {
    let line = readLine()!.split(separator: " ").map { Int($0)! }
    let (n, m) = (line[0], line[1])
    var arr = [[Int]]()

    for _ in 0..<n {
        let line = Array(readLine()!).map { Int(String($0))! }
        arr.append(line)
    }

    var ret = 0 // 최댓값

    // 가로: 0, 세로: 1

    for s in 0..<(1 << (n * m)) {
        var sum = 0

        for i in 0..<n {
            var cur = 0
            for j in 0..<m {
                let k = i * m + j
                if (s & (1 << k)) == 0 {
                    cur = cur * 10 + arr[i][j]
                } else {
                    sum += cur
                    cur = 0
                }
            }
            sum += cur
        }

        for j in 0..<m {
            var cur = 0
            for i in 0..<n {
                let k = i * m + j
                if (s & (1 << k)) != 0 {
                    cur = cur * 10 + arr[i][j]
                } else {
                    sum += cur
                    cur = 0
                }
            }
            sum += cur
        }

        ret = max(ret, sum)
    }

    print(ret)
}

solve()