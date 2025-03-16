import Foundation

func solution(_ array:[Int]) -> Int {
    array.map { String($0) }.joined().filter { $0 == "7" }.count
}