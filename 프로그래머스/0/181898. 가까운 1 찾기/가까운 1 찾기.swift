import Foundation

func solution(_ arr:[Int], _ idx:Int) -> Int {
    for i in idx..<arr.count {
        if arr[i] == 1 {
            return i
        }
    }
    return -1
}