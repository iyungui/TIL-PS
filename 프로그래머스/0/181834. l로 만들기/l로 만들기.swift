import Foundation

func solution(_ myString:String) -> String {
    myString.map {
        if($0 < "l") {
            return "l"
        } else {
            return String($0)
        }
    }.joined()
}