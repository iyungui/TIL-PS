func solution(_ s:String) -> String {
    let words = s.components(separatedBy: " ")
    let jadenCaseWords: [String] = words.map { (word: String) -> String in
        guard !word.isEmpty else { return "" }
        return word.prefix(1).uppercased() + word.dropFirst().lowercased()
    }
    return jadenCaseWords.joined(separator: " ")
}