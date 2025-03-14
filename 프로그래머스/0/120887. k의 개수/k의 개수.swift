import Foundation

func solution(_ i:Int, _ j:Int, _ k:Int) -> Int {
    // let a = stride(from: i, through: j, by: 1)
    //     .filter { String($0).contains(String(k)) }
    //     .map { String($0) }
    //     .joined()
    // var sum = 0
    // a.forEach {
    //     if k == Int(String($0))! { sum += 1}
    // }
    // return sum
    return (i...j).map {
        String($0).filter { String($0) == String(k) }.count
    }.reduce(0, +)
}