import Foundation

func solution(_ lines:[[Int]]) -> Int {
    
    var dict = [Int: Int]() // (range: count)
    
    for line in lines {
        for i in line[0]..<line[1] {
            dict[i, default: 0] += 1
        }
    }
    print(dict)
    return dict.values.filter { $0 > 1 }.count
}