func solution(_ n:Int, _ arr1:[Int], _ arr2:[Int]) -> [String] {
    var ret = [String]()
    
    for (a, b) in zip(arr1, arr2) {
        var aa = String(a, radix: 2)
        var bb = String(b, radix: 2)
        while aa.count < n { aa = "0" + aa }
        while bb.count < n { bb = "0" + bb }
        
        var row = ""
        for (aaa, bbb) in zip(aa, bb) {
            if String(aaa) + String(bbb) == "00" { row += " " }
            else { row += "#" }
        }
        ret.append(row)
    }
    return ret
}