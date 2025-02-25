import Foundation

func solution(_ arr:[Int], _ queries:[[Int]]) -> [Int] {
    var result: [Int] = []
    for query in queries {
        let (s, e, k) = (query[0], query[1], query[2])
        var temp: [Int] = []
        Array(arr[s...e]).forEach {
            if($0 > k) { temp.append($0) }
        }
        if !temp.isEmpty { result.append(temp.min()!) }
        else { result.append(-1) }
    }
    return result
}