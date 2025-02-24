import Foundation

func solution(_ my_string:String, _ s:Int, _ e:Int) -> String {
    var arr = Array(my_string)
    arr[s...e].reverse()
    return String(arr)
}