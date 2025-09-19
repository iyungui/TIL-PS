import Foundation

func main() {
    let n = Int(readLine()!)!
    var price = [[Int]]()
    for _ in 0..<n {
        let input = readLine()!.split(separator: " ").map { Int($0)! }
        price.append(input)
    }
    var flowers = Array(repeating: Array(repeating: false, count: n), count: n)

    var ret = Int.max
    func go(_ cnt: Int) {
        if cnt == 3 {
            ret = min(ret, calc(flowers))
            return
        }

        for i in 1..<n - 1 {
            for j in 1..<n - 1 {
                if flowers[i][j] || flowers[i - 1][j] || flowers[i + 1][j] || flowers[i][j - 1] || flowers[i][j + 1] {
                    continue
                }
                flowers[i][j] = true
                flowers[i - 1][j] = true
                flowers[i + 1][j] = true
                flowers[i][j - 1] = true
                flowers[i][j + 1] = true
                go(cnt + 1)
                flowers[i][j] = false
                flowers[i - 1][j] = false
                flowers[i + 1][j] = false
                flowers[i][j - 1] = false
                flowers[i][j + 1] = false
            }
        }
    }

    func calc(_ flowers: [[Bool]]) -> Int {
        var sum = 0
        for i in 0..<n {
            for j in 0..<n {
                if flowers[i][j] {
                    sum += price[i][j]
                }
            }
        }
        return sum
    }
    go(0)
    print(ret)
}

main()