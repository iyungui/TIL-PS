import Foundation

func main() {
    let (n, price) = input()
    let dy = [-1, 0, 1, 0]
    let dx = [0, 1, 0, -1]

    var flowers = Array(repeating: Array(repeating: false, count: n), count: n)

    var ret = Int.max

    func input() -> (Int, [[Int]]) {
        let n = Int(readLine()!)!
        var price = [[Int]]()

        for _ in 0..<n {
            let line = readLine()!.components(separatedBy: " ").map { Int($0)! }
            price.append(line)
        }

        return (n, price)
    }

    func check(_ y: Int, _ x: Int) -> Bool {
        if flowers[y][x] { return false }
        for i in 0..<4 {
            let ny = y + dy[i]
            let nx = x + dx[i]
            if ny < 0 || ny >= n || nx < 0 || nx >= n { return false }
            if flowers[ny][nx] { return false }
        }
        return true 
    }

    func setFlower(_ y: Int, _ x: Int) -> Int {
        var cost = price[y][x]
        flowers[y][x] = true

        for i in 0..<4 {
            let ny = y + dy[i]
            let nx = x + dx[i]
            flowers[ny][nx] = true
            cost += price[ny][nx]
        }

        return cost
    }

    func eraseFlower(_ y: Int, _ x: Int) {
        flowers[y][x] = false

        for i in 0..<4 {
            let ny = y + dy[i]
            let nx = x + dx[i]
            flowers[ny][nx] = false
        }
    }

    func go(_ cnt: Int, _ cost: Int) {
        if cnt == 3 {
            ret = min(ret, cost)
            return
        }

        for i in 1..<n - 1 {
            for j in 1..<n - 1 {
                if check(i, j) {
                    go(cnt + 1, cost + setFlower(i, j))
                    eraseFlower(i, j)
                }
            }
        }
    }

    go(0, 0)

    print(ret)
}

main()