func solution(_ arr:[Int]) -> Double {
    return arr.reduce(0.0) { Double($0) + Double($1) } / Double(arr.count)
}