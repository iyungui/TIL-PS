import Foundation

func solution(_ names:[String]) -> [String] {
    var result: [String] = []
    
    let groupCount = (names.count + 4) / 5
    
    for i in 0..<groupCount {
        let index = i * 5
        result.append(names[index])
    }
    
    return result
}