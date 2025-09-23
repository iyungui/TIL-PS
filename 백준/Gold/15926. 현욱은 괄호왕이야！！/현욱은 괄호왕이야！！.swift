import Foundation

func main() {
    let n = Int(readLine()!)!
    
    let str = Array(readLine()!)
    var stk = [Int]()
    var d = [Int](repeating: 0, count: n + 1)
    
    for i in 0..<str.count {
        if str[i] == "(" { stk.append(i) }
        else if !stk.isEmpty {
            d[stk.last!] = 1
            d[i] = 1
            _ = stk.popLast()
        }
    }
    
    var cnt = 0
    var ret = 0
    
    for i in d {
        if i == 1 { cnt += 1 }
        else { ret = max(ret, cnt); cnt = 0 }
    }
    
    print(ret)
}

main()