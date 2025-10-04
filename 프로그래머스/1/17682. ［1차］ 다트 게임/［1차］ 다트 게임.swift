func solution(_ dartResult:String) -> Int {
    let dart = Array(dartResult)
    var cur = ""
    var total: [Int] = []
    for i in 0..<dart.count {
        if dart[i].isNumber {
            cur.append(dart[i])
        }
        else {
            if dart[i] == "S" {
                let num = Int(cur)!
                total.append(num)
            }
            else if dart[i] == "D" {
                let num = Int(cur)! * Int(cur)!
                total.append(num)
            }
            else if dart[i] == "T" {
                let num = Int(cur)! * Int(cur)! * Int(cur)!
                total.append(num)
            }
            
            else if dart[i] == "*" {
                let idx = total.count - 1
                if idx > 0 {
                    total[idx - 1] *= 2
                }
                total[idx] *= 2
            }
            else if dart[i] == "#" {
                let idx = total.count - 1
                total[idx] = total[idx] * -1
            }
            cur = ""
        }
    }
    return total.reduce(0, +)
}