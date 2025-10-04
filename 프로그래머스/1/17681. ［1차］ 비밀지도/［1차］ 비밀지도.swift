func solution(_ n:Int, _ arr1:[Int], _ arr2:[Int]) -> [String] {
    return (0..<n).map { i in
        let binary = String(arr1[i] | arr2[i], radix: 2)
        let padded = String(repeating: "0", count: n - binary.count) + binary
        return padded.reduce("") { $0 + ($1 == "1" ? "#" : " ") }
    }
}