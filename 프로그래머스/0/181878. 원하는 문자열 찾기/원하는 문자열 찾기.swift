import Foundation

func solution(_ myString:String, _ pat:String) -> Int {
    myString.lowercased().contains(pat.lowercased()) ? 1 : 0
}