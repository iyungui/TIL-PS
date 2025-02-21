import Foundation

func solution(_ myString:String) -> [String] {
    myString.components(separatedBy: "x").filter{ !($0 == "") }.sorted()
}