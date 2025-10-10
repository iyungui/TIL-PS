import Foundation

func solution(_ numbers:[Int64]) -> [Int] {
    return numbers.map { solve($0) ? 1 : 0 }
}

private func solve(_ num: Int64) -> Bool {
    var binary = String(num, radix: 2)
    var k = 1
    while (1 << k) - 1 < binary.count { k += 1 }
    let padding = (1 << k) - 1 - binary.count
    binary = String(repeating: "0", count: padding) + binary
    return go(Array(binary), 0, binary.count - 1)
}

private func go(_ arr: [Character], _ left: Int, _ right: Int) -> Bool {
    if left > right { return true }
    let mid = (left + right) / 2
    if arr[mid] == "0" {
        for i in left...right {
            if arr[i] == "1" { return false }
        }
        return true
    } 
    return go(arr, left, mid - 1) && go(arr, mid + 1, right)
}