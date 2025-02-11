import Foundation

func solution(_ arr:[Int], _ n:Int) -> [Int] {
    var ret: [Int] = arr
    let startIndex: Int = arr.count % 2 == 1 ? 0 : 1
    for i in stride(from: startIndex, to: arr.count, by: 2) {
        ret[i] += n
    }
    
    return ret
}