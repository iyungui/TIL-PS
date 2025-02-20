import Foundation

func solution(_ str_list:[String], _ ex:String) -> String {
    str_list.filter { !$0.contains(ex) }.joined()
}