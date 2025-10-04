import Foundation

func main() {
    let str = readLine()!
    let bomb = Array(readLine()!)
    let cnt = bomb.count

    var stk = [Character]()

    for ch in str {
        stk.append(ch)

        if stk.count >= cnt {
            var flag = true

            for i in 0..<cnt {
                let idx = stk.count - cnt + i
                if stk[idx] != bomb[i] { flag = false; break }
            }

            if flag { stk.removeLast(cnt) }
        }
    }
    print(stk.isEmpty ? "FRULA" : String(stk))
}

main()