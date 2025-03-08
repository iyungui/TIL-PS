import Foundation

func solution(_ my_string:String, _ m:Int, _ c:Int) -> String {
    my_string.enumerated().filter {
        $0.offset % m == c - 1
    }.map { String($0.element) }.joined()
}