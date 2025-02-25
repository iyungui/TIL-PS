import Foundation

func solution(_ my_string:String, _ queries:[[Int]]) -> String {
    var str = Array(my_string)
    queries.forEach {
        str[$0[0]...$0[1]].reverse()
    }
    return String(str)
}