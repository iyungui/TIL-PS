func solution(_ msg:String) -> [Int] {
    var dict = [String: Int]()
    
    for i in 1...26 {
        let ch = String(UnicodeScalar(64 + i)!)
        dict[ch] = i
    }
    
    var iter = msg.makeIterator()
    var ret = [Int]()
    var key = ""
    while let c = iter.next() {
        let newKey = key + String(c)
        
        if dict[newKey] != nil {
            key.append(c)
        } else {
            dict[newKey] = dict.count + 1
            ret.append(dict[key]!)
            key = String(c)
        }
    }
    ret.append(dict[key]!)
    return ret
}