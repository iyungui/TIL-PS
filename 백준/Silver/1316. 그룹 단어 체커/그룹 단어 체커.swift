import Foundation

func go(_ str: String) -> Bool {
    var dict = [Character: Bool]()
    var prev: Character? = nil
    for ch in str {
        if prev != ch && dict[ch] == true { return false }
        dict[ch] = true
        prev = ch
    }
    return true
}

func solve() {
    let n = Int(readLine()!)!
    var cnt = 0
    for _ in 0..<n {
        let str = readLine()!
        if go(str) { cnt += 1 }
    }
    print(cnt)
}

solve()