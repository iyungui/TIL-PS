import Foundation

func solution(_ my_string:String, _ index_list:[Int]) -> String {
    // let strArr = Array(my_string)    // [Character]
    // return index_list.map { String(strArr[$0]) }.joined()
    
    let strArr = my_string.map { String($0) }   // [String]
    return index_list.reduce("") { $0 + strArr[$1] }
}