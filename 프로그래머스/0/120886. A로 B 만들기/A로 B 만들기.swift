import Foundation

func solution(_ before:String, _ after:String) -> Int {
    before.sorted() == after.sorted() ? 1 : 0
}