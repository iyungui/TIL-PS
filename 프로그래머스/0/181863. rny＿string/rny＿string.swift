import Foundation

func solution(_ rny_string:String) -> String {
    var ret: String = ""
    for i in rny_string {
        if(i == "m") {
            ret += "rn"
        } else {
            ret += String(i)
        }
    }
    return ret
}