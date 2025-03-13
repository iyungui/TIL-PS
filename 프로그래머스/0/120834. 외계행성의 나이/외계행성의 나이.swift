import Foundation

func solution(_ age:Int) -> String {
    String(age).map {
        String(UnicodeScalar(Int($0.asciiValue!) - 48 + 97)!)
    }.joined()
}