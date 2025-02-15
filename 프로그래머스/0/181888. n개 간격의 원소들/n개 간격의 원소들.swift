import Foundation

func solution(_ num_list:[Int], _ n:Int) -> [Int] {
    var ret: [Int] = []
    for i in stride(from: 0, to: num_list.count, by: n) {
        ret.append(num_list[i])
    }
    return ret
}