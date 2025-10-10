func solution(_ msg:String) -> [Int] {
    var dict = [String: Int]()
    
    for i in 1...26 {
        let ch = String(UnicodeScalar(64 + i)!)
        dict[ch] = i
    }
    
    var ret = [Int]()
    
    let msg = Array(msg).map { String($0) }
    var index = 27
    
    var i = 0
    
    while i < msg.count {
        var j = i + 1
        var w = msg[i]
        
        while j <= msg.count {
            let c = j < msg.count ? msg[j] : ""
            let wc = w + c
            
            if dict[wc] != nil {
                w = wc
                j += 1
            } else {
                dict[wc] = index
                index += 1
                break
            }
        }
        ret.append(dict[w]!)
        i += w.count
    }
    
    return ret
}