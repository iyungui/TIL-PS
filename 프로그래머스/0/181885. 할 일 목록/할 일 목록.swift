import Foundation

func solution(_ todo_list:[String], _ finished:[Bool]) -> [String] {
    var ret: [String] = []
    for i in 0..<finished.count { 
        if(!finished[i]) {
            ret.append(todo_list[i])
        }
    }
    return ret
}