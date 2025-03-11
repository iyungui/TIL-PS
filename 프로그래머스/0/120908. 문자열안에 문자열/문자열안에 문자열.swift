import Foundation

func solution(_ str1:String, _ str2:String) -> Int {
    let flag = str1.contains(str2)
    return flag == true ? 1 : 2
}