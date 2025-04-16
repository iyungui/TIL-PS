func solution(_ n:Int64) -> [Int] {
    String(n).reversed().map { Int(String($0))! }
}