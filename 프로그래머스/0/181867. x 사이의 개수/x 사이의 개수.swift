import Foundation

func solution(_ myString:String) -> [Int] {
    return myString.split(separator: "x", omittingEmptySubsequences: false)
                  .map { String($0).count }
}