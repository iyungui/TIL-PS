import Foundation

func main() {
    let n = Int(readLine()!)!
    var arr: [Int] = []
    var ret = Int.max

    func go(_ here: Int) {
        if here == n - 1 {
            var sum = 0

            var i = 1

            // i: 열, j: 행
            while i <= (1 << (n - 1)) {
                var cnt = 0
                for j in 0..<n {
                    if arr[j] & i != 0 { cnt += 1 }
                }
                sum += min(cnt, n - cnt)
                i *= 2
            }

            ret = min(ret, sum)
            return
        }
        go(here + 1)
        arr[here] = ~arr[here]
        go(here + 1)
    }

    for _ in 0..<n {
        var value = 1, a = 0
        let line = readLine()!
        for ch in line {
            if ch == "T" { a += value }
            value *= 2
        }
        arr.append(a)
    }
    
    go(0)
    print(ret)
}

main()