import Foundation

func main() {
    let str = Array(readLine()!)
    let bomb = Array(readLine()!)
    let bombLength = bomb.count
    var stk = [Character]()
    
    for ch in str {
        stk.append(ch)

        if stk.count >= bombLength {
            var flag = true
            for i in 0..<bombLength {
                if stk[stk.count - bombLength + i] != bomb[i] {
                    flag = false
                    break
                }
            }
            if flag {
                stk.removeLast(bombLength)
            }
        }
    }

    print(stk.isEmpty ? "FRULA" : String(stk))
}

main()