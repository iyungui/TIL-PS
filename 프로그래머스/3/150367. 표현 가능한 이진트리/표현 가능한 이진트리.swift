import Foundation

func solution(_ numbers: [Int64]) -> [Int] {
    func go(_ binary: [Character], _ left: Int, _ right: Int) -> Bool {
        if left > right { return true }

        let mid = (left + right) / 2

        if binary[mid] == "0" {
            for i in left...right {
                if binary[i] == "1" { return false }
            }
            return true
        }
        let l = go(binary, left, mid - 1)
        let r = go(binary, mid + 1, right)

        return l && r
    }

    func solve(_ n: Int64) -> Bool {
        var binary = String(n, radix: 2)
        var k = 1
        while (1 << k) - 1 < binary.count { k += 1 }
        let padding = (1 << k) - 1 - binary.count
        binary = String(repeating: "0", count: padding) + binary
        return go(Array(binary), 0, binary.count - 1)
    }

    return numbers.map { solve($0) ? 1 : 0 }
}