func solution(_ s:String) -> String {
    return s
    .components(separatedBy: " ")
    .filter { $0 != " " }
    .map { $0.prefix(1).uppercased() + $0.dropFirst().lowercased() }
    .joined(separator: " ")
}