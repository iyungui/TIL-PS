import Foundation

var n = 0, m = 0
var words = Array(repeating: 0, count: 51)

func count(_ mask: Int) -> Int {
    var cnt = 0
    for word in words[0..<n] {
        if word != 0 && (word & mask) == word {
            cnt += 1
        }
    }
    return cnt
}

func go(_ index: Int, _ k: Int, _ mask: Int) -> Int {
    if k < 0 { return 0 }
    if index == 26 { return count(mask) }
    
    var ret = go(index + 1, k - 1, mask | (1 << index))
    
    // a, n, t, i, c가 아닌 경우에만 선택하지 않는 옵션을 고려
    let aIndex = Character("a").asciiValue! - Character("a").asciiValue!  // 0
    let nIndex = Character("n").asciiValue! - Character("a").asciiValue!  // 13
    let tIndex = Character("t").asciiValue! - Character("a").asciiValue!  // 19
    let iIndex = Character("i").asciiValue! - Character("a").asciiValue!  // 8
    let cIndex = Character("c").asciiValue! - Character("a").asciiValue!  // 2
    
    if index != aIndex && index != nIndex && index != tIndex && index != iIndex && index != cIndex {
        ret = max(ret, go(index + 1, k, mask))
    }
    
    return ret
}

func solve() {
    let input = readLine()!.split(separator: " ").map { Int($0)! }
    n = input[0]
    m = input[1]
    
    for i in 0..<n {
        let word = readLine()!
        for char in word {
            let charIndex = Int(char.asciiValue! - Character("a").asciiValue!)
            words[i] |= (1 << charIndex)
        }
    }
    
    print(go(0, m, 0))
}

solve()