import Foundation

func solution(_ my_string:String, _ index_list:[Int]) -> String {
    // let arr: [Character] = Array(my_string)
    
    // return index_list.map {
    //     String(arr[$0])
    // }.joined()
    
    let strArr: [String] = my_string.map { String($0) }
    return index_list.reduce("") {
        return $0 + strArr[$1]
    }
}