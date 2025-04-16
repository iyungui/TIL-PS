func solution(_ s:String) -> String {
    let arr = s.components(separatedBy: " ").map { Int($0)! }
    return "\(arr.min()!) \(arr.max()!)"
}