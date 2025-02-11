import Foundation

func solution(_ myString:String, _ pat:String) -> Int {
    let temp: String = String(myString.map { $0 == "A" ? "B" : "A" })
    return temp.contains(pat) ? 1 : 0
}