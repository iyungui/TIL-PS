import Foundation

func solution(_ s:String) -> [Int] {
    let a = s.components(separatedBy: "}").filter { !$0.isEmpty }
    var dict: [Int : Int] = [:]
    for c in a {
        var dropedStr = c.dropFirst(2).components(separatedBy: ",")
        for ch in dropedStr {
            dict[Int(ch)!, default: 0] += 1
        }
    }
    let sortedDict = dict.sorted{ $0.value > $1.value }
    var res: [Int] = []
    for (key, value) in sortedDict {
        res.append(key)
    }
    return res
}