import Foundation

func solution(_ arr:[Int]) -> [Int] {
    // let indices = arr.enumerated().filter { $0.element == 2 }.map { $0.offset }
    // guard !indices.isEmpty else {
    //     return [-1]
    // }
    // let first = indices[0]
    // let last = indices[indices.count - 1]
    // return Array(arr[first...last])
    
    if let s = arr.firstIndex(of: 2), let e = arr.lastIndex(of: 2) {
        return Array(arr[s...e])
    } else {
        return [-1]   
    }
}