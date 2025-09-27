import Foundation

func solve() {
    let line = readLine()!
    let croatianAlphabets = ["c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="]
    
    var count = 0
    var i = 0
    let chars = Array(line)
    
    while i < chars.count {
        var found = false
        
        // 3글자 크로아티아 알파벳 먼저 확인 (dz=만 해당)
        if i + 2 < chars.count {
            let threeChar = String(chars[i..<i+3])
            if threeChar == "dz=" {
                count += 1
                i += 3
                found = true
            }
        }
        
        // 2글자 크로아티아 알파벳 확인
        if !found && i + 1 < chars.count {
            let twoChar = String(chars[i..<i+2])
            if croatianAlphabets.contains(twoChar) {
                count += 1
                i += 2
                found = true
            }
        }
        
        // 일반 알파벳 (1글자)
        if !found {
            count += 1
            i += 1
        }
    }
    
    print(count)
}

solve()