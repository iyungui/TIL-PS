import Foundation

func solution(_ strArr:[String]) -> Int {
    // var cnt = Array(repeating: 0, count: 31) 
    // strArr.forEach {
    //     cnt[$0.count] += 1
    // }
    // return cnt.max()!
    let groups = Dictionary(grouping: strArr) { $0.count }  // count 문자열 길이가 키가 됨
    return groups.values.map { $0.count }.max() ?? 0
}