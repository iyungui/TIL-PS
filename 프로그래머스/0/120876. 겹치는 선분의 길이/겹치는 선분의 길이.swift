import Foundation

func solution(_ lines:[[Int]]) -> Int {
    let mx = lines.map { $0[1] }.max()!
    let mn = lines.map { $0[0] }.min()!
    
    // Calculate the total range and offset
    // For example the mn value is -1 and mx value is 3, and the offset is 1 because the offset is abs(-1) = 1
    // So, the range is (-1, 0, 1, 2). (count is 4)
    // if range is mx + offset = 3 + 1 = 4. 
    
    let offset = abs(mn)
    let range = mx + offset
    
    var checked = Array(repeating: 0, count: range + 1)
    lines.forEach {
        for i in $0[0] + offset..<$0[1] + offset {
            checked[i] += 1
        }
    }
    
    var count: Int = 0
    for i in 0..<checked.count {
        if checked[i] > 1 {
            count += 1
        }
    }
    
    return count
}