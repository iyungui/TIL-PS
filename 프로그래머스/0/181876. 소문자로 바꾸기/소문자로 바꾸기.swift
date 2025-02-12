import Foundation

func solution(_ myString:String) -> String {
    // myString.map { $0.lowercased() }.joined()    // bad
    myString.lowercased()
}