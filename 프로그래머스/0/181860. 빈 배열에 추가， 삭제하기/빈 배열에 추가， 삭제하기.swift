import Foundation

func solution(_ arr:[Int], _ flag:[Bool]) -> [Int] {
    var ret: [Int] = []
    for (i, isAdd) in flag.enumerated() {
        if isAdd {
            for _ in 0..<arr[i] * 2 {
                ret.append(arr[i])
            }
        } else {
            for _ in 0..<arr[i] {
                ret.removeLast()
            }
        }
    }
    return ret
}