func solution(_ s:String) -> String {
    s
    .components(separatedBy: " ")
    .map { (word: String) -> String in
        return word.prefix(1).uppercased() + word.dropFirst().lowercased()
    }
    .joined(separator: " ")
}