import Foundation

func solution(_ picture:[String], _ k:Int) -> [String] {
    var result: [String] = []
    for row in picture {
        var str: String = ""
        for i in row {
            str += String(repeating: i, count: k)
        }
        for _ in 0..<k {
            result.append(str)
        }
    }
    return result
    // S1
    // var result: [String] = []
    // for row in picture {
    //     var str: String = ""
    //     for i in row {
    //         str += String(repeating: i, count: k)
    //     }
    //     for _ in 0..<k {
    //         result.append(str)
    //     }
    // }
    // return result
    
    // S2
    // return picture.flatMap { Array(repeating: $0.map { String(repeating: $0, count: k) }.joined(), count: k) }
}