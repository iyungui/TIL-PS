func solution(_ n:Int, _ arr1:[Int], _ arr2:[Int]) -> [String] {
    var answer: [String] = []
    for (a, b) in zip(arr1, arr2) {
        var a = String(a, radix: 2)
        var b = String(b, radix: 2)
        while a.count < n { a = "0" + a }
        while b.count < n { b = "0" + b }
        var row: String = ""
        for (aa, bb) in zip(a, b) {
            row += (String(aa) + String(bb) == "00") ? " " : "#"
        }
        answer.append(row)
    }
    
    return answer
}