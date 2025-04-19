
import Foundation

let n: Int = Int(readLine()!)!
let p: [Character] = Array(readLine()!)

let starIdx = p.firstIndex(of: "*")!

// 별표를 기준으로 왼쪽 패턴: prefix
let prefix = String(p[..<starIdx])
// 오른쪽
let suffix = String(p[(starIdx + 1)...])

for _ in 0..<n {
    let temp = readLine()!
    
    if temp.count < prefix.count + suffix.count {
        print("NE")
        continue
    }
    
    if !temp.hasPrefix(prefix) {
        print("NE")
        continue
    }
    
    if !temp.hasSuffix(suffix) {
        print("NE")
        continue
    }
    
    print("DA")
}