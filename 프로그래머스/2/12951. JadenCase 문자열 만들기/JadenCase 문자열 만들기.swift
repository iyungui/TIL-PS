func solution(_ s:String) -> String {
    s
    .components(separatedBy: " ")
    .filter { $0 != " " }
    .map { (word: String) -> String in
        return word.prefix(1).uppercased() + word.dropFirst().lowercased()
    }   // [String]
    .joined(separator: " ") // String
}