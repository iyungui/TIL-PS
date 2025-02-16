import Foundation

func solution(_ my_string:String, _ index_list:[Int]) -> String {
    let strArr = Array(my_string)
    return index_list.map { String(strArr[$0]) }.joined()
}