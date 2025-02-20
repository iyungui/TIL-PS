import Foundation

func solution(_ num_list:[Int]) -> [Int] {
    var ret: [Int] = num_list
    let last: Int = num_list[num_list.count - 1]
    let lastPrev: Int = num_list[num_list.count - 2]
    if(last > lastPrev) {
        ret.append(last - lastPrev)
    } else {
        ret.append(last * 2)
    }
    return ret
}